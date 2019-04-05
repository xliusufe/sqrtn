#include <stdlib.h>
#include <stdio.h>
#include <R.h>
#include <Rinternals.h> 
#include <string.h> 

int findk(int *de, int digit, int fd) {
	int temp = 0;
	for (int i = 0; i < digit; i++, de++) {
		temp = 10 * temp + *de;
	}
	return temp * 5 / fd;
}

void divide_20k(int *d, int *q, int k, int Lq) {
	int temp, temp1 = k * k;
	temp = *d - temp1 % 10;	temp1 /= 10;
	if (temp >= 0) {*d = temp;d--;}
	else {*d = temp + 10;d--;(*d)--;}
	k *= 2;
	for (int i = 0; i < Lq; i++) {
		temp1 += (*q)*k;q--;
		temp = *d - temp1 % 10;
		temp1 /= 10;
		if (temp >= 0) {*d = temp;	d--;}
		else {*d = temp + 10;d--;(*d)--;}
	}
	while (temp1) {
		temp = *d - temp1 % 10;	temp1 /= 10;
		if (temp >= 0) {*d = temp;d--;}
		else {*d = temp + 10;d--;(*d)--;}
	}
}

void abnormal(int *d, int *q, int k, int Lq) {
	int temp1 = (k * 2) - 1;
	*d -= 1;
	for (int i = 0; i < Lq; i++) {
		temp1 += (*q) * 20 + *d - 9;
		q--;
		while (temp1 < 0) {temp1 += 10; *(d - 1)-=1; }
		*d = temp1 % 10;d--;temp1 /= 10;
	}
	while (temp1) {*d = temp1 % 10;d--;temp1 /= 10;}
	while (*d != -1) { *d = 0; d--; }
	*d = 0;
}

int searchk(int *de, int Ld, int pre) {
	int number = 0;
	pre = pre << 1;
	for (int i = Ld; i > 0; i--)
	{number = number * 10 + *de; de++;}
	int c = number / pre;
	while (c*(c + pre) > number) c--;
	return c;
}

void divi(char *qt, int prec, int number, int Ln) {
	int k, Lq = 1, pr = 0, digit = 4, *de, para = 5, fd = 1;
	int *q = (int *)calloc(prec, sizeof(int));
	int *qe = q;
	int *d = (int *)calloc(prec * 2, sizeof(int));
	if (Ln % 2) digit = 0; else digit = 1; 
	de = d + Ln;
	while (number) { de--; *de = number % 10; number /= 10; }

	k = *de;
	if (!(Ln % 2)) { d++; k = k * 10 + *d; }
	while (k >= fd * fd) fd++;
	fd--; *q = fd; Lq = 1; pr++; k = fd * fd;
	if (k >= 10)
	{	*d -= k % 10;
		if (*d < 0) { *d += 10; (*de)--; }
		*de -= k / 10;
	}
	else {*d -= k;
		if (*d < 0) { *d += 10; (*de)--; }
	}
	while (!(*de)) { de++; digit--; }
	while (pr < para)
	{
		d += 2; digit += 2; fd *= 10;
		k = searchk(de, digit + Lq, fd);
		if (k) { divide_20k(d, q, k, Lq); }
		while (!(*de)) { de++; digit--; }
		q++; *q = k; Lq++; pr++; digit--; fd += k;
	}
	digit += para;
	while (pr < prec)
	{
		k = findk(de, digit, fd);d += 2;
		if (k) {divide_20k(d, q, k, Lq);
			if (*(de - 1) < 0) { abnormal(d, q, k, Lq); k--; }
			while (!(*de)) { de++; digit--; }
		}
		if (k >= 10) {
			*q += k / 10;
			if (*q >= 10) { *(q - 1) += *q / 10; *q = *q % 10; }
			q++;*q = k % 10;
		}
		else { q++; *q = k; }
		Lq++;digit++;pr++;
	}
	
	int i = (Ln - 1) / 2; 
	prec -= Ln/2+Ln%2;
	for (; i >= 0; i--, qe++, qt++) { *qt = *qe + 48; }
	*qt = '.'; qt++;
	for (; prec > 0; prec--, qe++, qt++) { *qt = *qe + 48; }
	*qt='\0';
}

SEXP sqrtn2(SEXP prec0, SEXP N)
{
	int n = INTEGER(N)[0], prec = INTEGER(prec0)[0], i, Ln;
	SEXP rquotient_s, rprec, list, list_names;
	PROTECT(rquotient_s = allocVector(STRSXP, 1));
	PROTECT(rprec       = allocVector(INTSXP, 1));
	PROTECT(list        = allocVector(VECSXP, 2));
	PROTECT(list_names  = allocVector(STRSXP, 2));
	char *names[2] = { "sqrt2", "prec" };
	for (i = 0; i < 2; i++)
		SET_STRING_ELT(list_names, i, mkChar(names[i]));
	INTEGER(rprec)[0] = prec;

	char *quotient_s;
	for(i=n,Ln=1;i>=10;i/=10,Ln++);
	if (Ln % 2) {prec += Ln / 2+1;}
	else{prec += Ln / 2;}
	quotient_s = (char *)malloc(sizeof(char)*(prec+2));
	divi(quotient_s, prec, n, Ln);

	SET_STRING_ELT(rquotient_s, 0, mkChar(quotient_s));
	SET_VECTOR_ELT(list, 0, rquotient_s);
	SET_VECTOR_ELT(list, 1, rprec);
	setAttrib(list, R_NamesSymbol, list_names);
	UNPROTECT(4);
	return(list);
}