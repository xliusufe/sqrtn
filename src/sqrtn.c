#include <stdio.h>  // required for exit
#include <stdlib.h> // required for malloc(), free();
#include <R.h>
#include <Rinternals.h>  // required for SEXP et.al.;
#include <string.h> // required for memcpy()
#define min(a,b) ((a > b) ? b : a)
#define max(a,b) ((a > b) ? a : b)

int pell2(int *a1, int *b1, int *Lab, int N, int L0){
	int i,n=14,La,ta,tb,ta1,tb1,*a,*b;
	a1[0]=7;b1[0]=5; a1[1]=0;b1[1]=4; a1[2]=0;b1[2]=0;	a1[3]=6;b1[3]=0;
	a1[4]=8;b1[4]=7; a1[5]=1;b1[5]=3; a1[6]=2;b1[6]=5; a1[7]=1;b1[7]=4;
	a1[8]=8;b1[8]=6; a1[9]=0;b1[9]=7; a1[10]=1;
	Lab[0]=11;Lab[1]=10;Lab[2]=n;	
	while(n<N){
		ta=tb=0;a=&a1[0];b=&b1[0];
		La=Lab[0]+1;
		for(i=0;i<La;i++){
			ta1=(*a)*17+(*b)*24+ta;
			tb1=(*a)*12+(*b)*17+tb;
			*a=ta1%10;	*b=tb1%10;
			ta=ta1/10;	tb=tb1/10;	
			a++;b++;
		}
		Lab[0]=La;Lab[1]=La;
		if(ta){*a+=ta;Lab[0]++;}
		if(tb){*b+=tb;Lab[1]++;}
		if(Lab[1]+1>=L0) return 1;
		n+=2;
	}		
	return 0;
}

int pell3(int *a1, int *b1, int *Lab, int N, int L0){
	int i,n=8,La,ta,tb,ta1,tb1,*a,*b;
	a1[0]=1;b1[0]=0; a1[1]=5;b1[1]=4;	a1[2]=1;b1[2]=3; a1[3]=2;b1[3]=6;
	a1[4]=8;b1[4]=2; a1[5]=3;b1[5]=6;	a1[6]=3;b1[6]=4; a1[7]=6;b1[7]=9;
	a1[8]=8;b1[8]=6; a1[9]=9;b1[9]=5;
	Lab[0]=10;Lab[1]=10;Lab[2]=n;	
	while(n<N){
		ta=tb=0;a=&a1[0];b=&b1[0];
		La=Lab[0]+2;
		for(i=0;i<La;i++){
			ta1=(*a)*97+(*b)*168+ta;
			tb1=(*a)*56+(*b)*97+tb;
			*a=ta1%10;*b=tb1%10;
			ta=ta1/10;tb=tb1/10;	
			a++;b++;
		}
		Lab[0]=La;Lab[1]=La;
		if(ta){*a+=ta;Lab[0]++;}
		if(tb){*b+=tb;Lab[1]++;}
		if(Lab[1]+1>=L0) return 1;
		n+=2;
	}		
	return 0;
}

int pell5(int *a1, int *b1, int *Lab, int N, int L0){
	int i,n=10,La,ta,tb,ta1,tb1,*a,*b;	
	a1[0]=9;b1[0]=6; a1[1]=0;b1[1]=3; a1[2]=8;b1[2]=6; a1[3]=6;b1[3]=5;
	a1[4]=7;b1[4]=8; a1[5]=0;b1[5]=7; a1[6]=0;b1[6]=3; a1[7]=5;b1[7]=3;
	a1[8]=4;b1[8]=1; a1[9]=6;b1[9]=3; a1[10]=9;b1[10]=4;
	Lab[0]=11;Lab[1]=11;Lab[2]=n;	
	while(n<N){
		ta=tb=0;a=&a1[0];b=&b1[0];
		La=Lab[0]+2;
		for(i=0;i<La;i++){
			ta1=(*a)*161+(*b)*360+ta;
			tb1=(*a)*72+(*b)*161+tb;
			*a=ta1%10;*b=tb1%10;
			ta=ta1/10;tb=tb1/10;	
			a++;b++;
		}
		Lab[0]=La;Lab[1]=La;
		if(ta){*a+=ta;Lab[0]++;}
		if(tb){*b+=tb;Lab[1]++;}
		if(Lab[1]+1>=L0) return 1;
		n+=2;
	}		
	return 0;
}

int pell7(int *a1, int *b1, int *Lab, int N, int L0){
	int i,n=10,La,ta,tb,ta1,tb1,*a,*b;	
	b1[0]=5;a1[0]=4; b1[1]=9;a1[1]=2; b1[2]=7;a1[2]=2; b1[3]=1;a1[3]=3;
	b1[4]=2;a1[4]=7; b1[5]=5;a1[5]=8; b1[6]=5;a1[6]=6; b1[7]=3;a1[7]=5;
	b1[8]=5;a1[8]=1; b1[9]=2;a1[9]=3; b1[10]=1;a1[10]=3;
	Lab[0]=11;Lab[1]=11;Lab[2]=n;	
	while(n<N){
		ta=tb=0;a=&a1[0];b=&b1[0];
		La=Lab[0]+2;
		for(i=0;i<La;i++){
			ta1=(*a)*127+(*b)*336+ta;
			tb1=(*a)*48+(*b)*127+tb;
			*a=ta1%10;*b=tb1%10;
			ta=ta1/10;tb=tb1/10;	
			a++;b++;
		}
		Lab[0]=La;Lab[1]=La;
		if(ta){*a+=ta;Lab[0]++;}
		if(tb){*b+=tb;Lab[1]++;}
		if(Lab[1]+1>=L0) return 1;
		n+=2;
	}		
	return 0;
}


void plus1(int *a, int b, int curr_len){
	int *pa=&a[curr_len-1];
	for(int i=0;i<curr_len;i++,pa--){
		b+=*pa;	*pa=b%10; b = b/10;
		if(!b) break;
	}
}

void minus0(int *a, int *b, int *pa2, int Lb){
	int i,temp,*pa,*pb=&b[0];
	pa=pa2;
	for(i=0;i<Lb;i++){
		temp=*pa-*pb; 
		if(temp>=0){*pa=temp;pa++;}
		else{*pa=temp+10;pa++;(*pa)--;}
		pb++;
	}
}

void divide_k(int *a, int *b, int La, int *pa2, int n){
	int i,*pa,*pb=&b[0];
	pa=pa2+La-1;pa=pa2;
	int temp,temp1=0;
	for(i=0;i<La;i++){
		temp1=(*pb)*n+temp1/10;
		temp=*pa-temp1%10; 
		if(temp>=0){*pa=temp;pa++;}
		else{*pa=temp+10;pa++;(*pa)--;}
		pb++;
	}
	if(temp1/10) *pa-=*pb;
	pa=pa2+La-1;
}

int divide_single(int *a, int *b, int La, int *pa1,int *pa2, int Lb, int digit,int tempb){
	int i,temp,temp1,*pa;	
	if(La>Lb){	
		pa=pa1-digit;
		temp=0;temp1=1;
		for(i=0;i<digit+1;i++,pa++){
			temp+=(*pa)*temp1;	temp1*=10;
		}
		temp1=temp/tempb;
		if(temp1==0) return 0;
		if(temp1==1) minus0(a,b,pa2,Lb);
		else{
			temp1 = min(temp1,temp/(tempb+1));
			if(temp1==1) minus0(a,b,pa2,Lb);
			else divide_k(a,b,La,pa2,temp1);
		}
	}
	else{
		pa=pa1-digit+1;
		temp=0;temp1=1;
		for(i=0;i<digit;i++,pa++){
			temp+=(*pa)*temp1;	temp1*=10;
		}
		temp1=temp/tempb;
		if(temp1==0) return 0;
		if(temp1==1) minus0(a,b,pa2,Lb);
		else{
			temp1 = min(temp1,temp/(tempb+1));
			if(temp1==1) minus0(a,b,pa2,Lb);
			else divide_k(a,b,La,pa2,temp1);
		}
	}
	return temp1;	
}

void divide(int *quotient, int *a, int *b, int La, int Lb,int prec){
	int i,pr=0,count,digit,temp1,tempb=0,*pa1,*pa2;
	if(Lb<8) digit=3;
	else digit=4;
	temp1=1;
	for(i=digit;i>0;i--){
		tempb+=b[Lb-i]*temp1; temp1*=10;
	}
	pa2=&a[2*prec-La]; 
	minus0(a,b,pa2,Lb);
	pa1=&a[2*prec-1];
	while(pr<prec){
		pa1=pa2+Lb-1;
		count=0;	
		while(!(*pa1)){count++;pa1--;}
		if(count){ 	
			if(count>1)	pr+=count-1;						
			La=Lb; pa2-=count; 
		}
		else{La=Lb+1; pa2--;}
		temp1 = divide_single(a,b,La,pa1,pa2,Lb,digit,tempb);	
		if(temp1<10) quotient[pr++]=temp1;
		else plus1(quotient,temp1,++pr);
	}	
}

void precesion(char *quotient_s, int prec,int n){	
	int i,*a,*b,*quotient;
	if(prec<22){
		quotient=(int *)malloc(sizeof(int)*22);
		a=(int *)malloc(sizeof(int)*21);
		b=(int *)malloc(sizeof(int)*21);
		if(n==2){
			quotient[0]=4;quotient[1]=1;quotient[2]=4;quotient[3]=2;
			quotient[4]=1;quotient[5]=3;quotient[6]=5;quotient[7]=6;
			quotient[8]=2;quotient[9]=3;quotient[10]=7;quotient[11]=3;
			quotient[12]=0;quotient[13]=9;quotient[14]=5;quotient[15]=0;
			quotient[16]=4;quotient[17]=8;quotient[18]=8;quotient[19]=0;
			quotient[20]=1;
		}
		if(n==3){
			quotient[0]=7;quotient[1]=3;quotient[2]=2;quotient[3]=0;
			quotient[4]=5;quotient[5]=0;quotient[6]=8;quotient[7]=0;
			quotient[8]=7;quotient[9]=5;quotient[10]=6;quotient[11]=8;
			quotient[12]=8;quotient[13]=7;quotient[14]=7;quotient[15]=2;
			quotient[16]=9;quotient[17]=3;quotient[18]=5;quotient[19]=2;
			quotient[20]=7;		
		}
		if(n==5){
			quotient[0]=2;quotient[1]=3;quotient[2]=6;quotient[3]=0;
			quotient[4]=6;quotient[5]=7;quotient[6]=9;quotient[7]=7;
			quotient[8]=7;quotient[9]=4;quotient[10]=9;quotient[11]=9;
			quotient[12]=7;quotient[13]=8;quotient[14]=9;quotient[15]=6;
			quotient[16]=9;quotient[17]=6;quotient[18]=4;quotient[19]=0;
			quotient[20]=9;	
		}
		if(n==7){
			quotient[0]=6;quotient[1]=4;quotient[2]=5;quotient[3]=7;
			quotient[4]=5;quotient[5]=1;quotient[6]=3;quotient[7]=1;
			quotient[8]=1;quotient[9]=0;quotient[10]=6;quotient[11]=4;
			quotient[12]=5;quotient[13]=9;quotient[14]=0;quotient[15]=5;
			quotient[16]=1;quotient[17]=6;quotient[18]=1;quotient[19]=5;
			quotient[20]=7;			
		}
	}  		
	else{
		quotient=(int *)malloc(sizeof(int)*prec);
		for(i=0;i<prec;i++) quotient[i]=0;
		a=(int *)malloc(sizeof(int)*2*prec);
		b=(int *)malloc(sizeof(int)*prec);
		int *Lab=(int *)malloc(sizeof(int)*3);
		Lab[0]=Lab[1]=Lab[2]=0;
		for(i=0;i<prec;i++) b[i]=0;
		for(i=0;i<2*prec;i++) a[i]=0;
		if(n==2) pell2(a,b,Lab,prec,prec/2);
		if(n==3) pell3(a,b,Lab,prec,prec/2);
		if(n==5) pell5(a,b,Lab,prec,prec/2);
		if(n==7) pell7(a,b,Lab,prec,prec/2);
		int *pa1=&a[2*prec-1],*pa2=&a[Lab[0]-1];
		for(i=0;i<Lab[0];i++,pa1--,pa2--){*pa1=*pa2;*pa2=0;}
		divide(quotient,a,b,Lab[0],Lab[1],prec);
		free(Lab);
	}
	if(n==2)quotient_s[0]='1';
	if(n==3)quotient_s[0]='1';
	if(n==5)quotient_s[0]='2';
	if(n==7)quotient_s[0]='2';
	quotient_s[1]='.';
	for(i=2;i<prec+2;i++) quotient_s[i] = quotient[i-2]+48;
	quotient_s[prec+2]='\0';
	free(a);free(b);free(quotient);
}

SEXP sqrtn(SEXP prec0, SEXP N)
{
	int *n_ = INTEGER(N);
	int *prec0_ = INTEGER(prec0);
	int n = n_[0],prec=prec0_[0],i;
	char *quotient_s;
	SEXP rquotient_s,rprec,list, list_names;
	quotient_s =(char *)malloc(sizeof(char)*(prec+3));	
	precesion(quotient_s,prec,n);	
	PROTECT(rquotient_s = allocVector(STRSXP, 1));
	SET_STRING_ELT(rquotient_s, 0,  mkChar(quotient_s));
	PROTECT(rprec = allocVector(INTSXP, 1));
	INTEGER(rprec)[0] = prec;
	char *names[2] = {"sqrt2", "prec"};
	PROTECT(list_names = allocVector(STRSXP, 2));
	for(i = 0; i < 2; i++)
		SET_STRING_ELT(list_names, i,  mkChar(names[i]));
	PROTECT(list = allocVector(VECSXP, 2)); 
	SET_VECTOR_ELT(list, 0, rquotient_s);
	SET_VECTOR_ELT(list, 1, rprec);  
	setAttrib(list, R_NamesSymbol, list_names); 	
	UNPROTECT(4);  
	return(list);	
}

