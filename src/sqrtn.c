#include <stdio.h>  // required for exit
#include <stdlib.h> // required for malloc(), free();
#include <R.h>
#include <Rinternals.h>  // required for SEXP et.al.;
#include <string.h> // required for memcpy()

#define max(a,b) ((a > b) ? a : b)

int plus(int *a, int *b, int curr_len){
	//add b to a
	int i;
	int temp,temp1=0;
	for(i=0;i<curr_len;i++){
		temp = a[i]+b[i]+temp1; 
		a[i]=temp%10;
		temp1 = temp/10;
	}
	if(temp1>0) a[curr_len++]=temp1;
	return curr_len;
}

int compare0(int *a, int *b, int La){
	int i;	
	for(i=La-1;i>=0;i--){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return 0;	
	}
	return 1;
}

void minus0(int *a, int *b, int Lb){
	int i,temp;
	for(i=0;i<Lb;i++){
		temp=a[i]-b[i]; 
		temp>=0?(a[i]=temp):(a[i]=temp+10,a[i+1]--);	
	}
}

int product_single(int *b, int curr_len, int n){
	int i,temp,temp1=0,flag;
	for(i=0;i<curr_len;i++){
		temp = b[i]*n+temp1; 
		b[i]=temp%10;
		temp1 = temp/10;
	}
	if(temp1>0){ b[curr_len]=temp1;flag=1;}
	else flag=0;
	return flag;
}

int pell(int *a, int *b, int *a1, int *b1, int *Lab, int N, int L0){
	int i,n=14,La,Lb,flaga,flagb;
	
	a[0]=7;b[0]=5;
	a[1]=0;b[1]=4;
	a[2]=0;b[2]=0;
	a[3]=6;b[3]=0;
	a[4]=8;b[4]=7;
	a[5]=1;b[5]=3;
	a[6]=2;b[6]=5;
	a[7]=1;b[7]=4;
	a[8]=8;b[8]=6;
	a[9]=0;b[9]=7;
	a[10]=1;

	Lab[0]=11;Lab[1]=10;
	for(i=0;i<Lab[0];i++)a1[i]=a[i];
    for(i=0;i<Lab[1];i++)b1[i]=b[i];
	Lab[2]=n;
	while(n<N){
		La = plus(a,b1,max(Lab[0],Lab[1]));
		flaga=product_single(a1,Lab[0],2);
		flagb=product_single(b1,Lab[1],3);
		
		La = plus(a,a1,max(La,Lab[0]+flaga));
		La = plus(a,b1,max(La,Lab[1]+flagb));			

		Lb = Lab[1]+flagb;
		for(i=0;i<Lb;i++) b[i]=b1[i];
		Lb = max(Lb,Lab[0]+flaga);		
		Lb = plus(b,a1,Lb);

		Lab[0]=La; Lab[1]=Lb; Lab[2]+=1;
		if(Lab[1]>=L0) return 1;
		n++;

		for(i=0;i<La;i++)a1[i]=a[i];
		for(i=0;i<Lb;i++)b1[i]=b[i];
	}	
	return 0;
}

int divide_k(int *a, int *b,int *bcopy, int La, int Lb, int temp1){
	int flag;

	if(temp1==1) minus0(a,bcopy,Lb);
	else{		
		flag=product_single(bcopy,Lb,temp1);
		Lb+=flag;
		if(compare0(a,bcopy,La))
			minus0(a,bcopy,Lb);
		else{
			minus0(bcopy,b,Lb);
			minus0(a,bcopy,Lb);			
			temp1--;
		}			
	}
	return temp1;
}

int divide_k0(int *a, int *b,int *bcopy, int La, int Lb, int temp1){
	int flag;

	if(temp1==0) return 0;
	else if(temp1==1){
		if(!compare0(a,bcopy,La)) return 0;
		minus0(a,bcopy,Lb);
	}
	else{		
		flag=product_single(bcopy,Lb,temp1);
		if(flag){		
			minus0(bcopy,b,Lb);
			minus0(a,bcopy,Lb);	
			temp1--;
		}
		else{
			if(compare0(a,bcopy,La))
				minus0(a,bcopy,Lb);
			else{
				minus0(bcopy,b,Lb);
				minus0(a,bcopy,Lb);			
				temp1--;
			}		
		}		
	}
	return temp1;
}

int divide_single(int *a, int *b,int *bcopy, int La, int Lb, int digit){
	int i,temp,temp1,tempb;	
	for(i=0;i<Lb;i++) bcopy[i]=b[i];bcopy[Lb]=0;

	if(La>Lb){
		temp=tempb=0;temp1=1;
		for(i=digit;i>0;i--){
			temp+=a[Lb+1-i]*temp1;
			temp1*=10;
		}
		temp1=1;
		for(i=digit-1;i>0;i--){
			tempb+=b[Lb-i]*temp1;
			temp1*=10;
		}
		temp1 = temp/tempb;
		temp1 = divide_k(a,b,bcopy,La,Lb,temp1);		
	}
	else{
		temp=tempb=0;temp1=1;
		for(i=digit;i>0;i--){
			temp+=a[Lb-i]*temp1;
			tempb+=b[Lb-i]*temp1;
			temp1*=10;
		}
		temp1 = temp/tempb;
		temp1 = divide_k0(a,b,bcopy,La,Lb,temp1);	
	}
	return temp1;	
}

void divide(int *quotient, int *a, int *b, int La, int Lb,int prec){
	int i,pr=0,count,Lb1=Lb+1,*bcopy,digit;
	bcopy=(int *)malloc(sizeof(int)*Lb1);
	if(Lb<8) digit=3;
	else digit=4;

	minus0(a,b,Lb);
	while(pr<prec){
		count=0;	
		while(!a[Lb-1-count]) count++;
		if(count){ 	
			if(count>1)	pr+=count-1;			
			for(i=Lb;i>=count;i--)a[i]=a[i-count];
			for(i=0;i<count;i++)a[i]=0;			
			La=Lb;
		}
		else{
			La=Lb+1;
			for(i=Lb;i>0;i--)a[i]=a[i-1]; a[0]=0; 			
		}
		quotient[pr++] = divide_single(a,b,bcopy,La,Lb,digit);	
	}	
	free(bcopy);
}

void precesion(int *quotient, int *a, int *b,int prec){	
	if(prec<22){
		quotient[0]=4;quotient[1]=1;quotient[2]=4;quotient[3]=2;
		quotient[4]=1;quotient[5]=3;quotient[6]=5;quotient[7]=6;
		quotient[8]=2;quotient[9]=3;quotient[10]=7;quotient[11]=3;
		quotient[12]=0;quotient[13]=9;quotient[14]=5;quotient[15]=0;
		quotient[16]=4;quotient[17]=8;quotient[18]=8;quotient[19]=0;
		quotient[20]=1;
	}  		
	else{
		int *a1=(int *)malloc(sizeof(int)*prec);
		int *b1=(int *)malloc(sizeof(int)*prec);
		int *Lab=(int *)malloc(sizeof(int)*3);
		Lab[0]=Lab[1]=Lab[2]=0;
		for(int i=0;i<prec;i++) a1[i]=b1[i]=a[i]=b[i]=0;

		pell(a,b,a1,b1,Lab,prec,prec/2);
		divide(quotient,a,b,Lab[0],Lab[1],prec);
		free(a1);free(b1);free(Lab);
	}
}

SEXP sqrtn(SEXP prec0, SEXP N)
{
	int *n_ = INTEGER(N);
	int *prec0_ = INTEGER(prec0);
	int n = n_[0],prec=prec0_[0], i, *a,*b,*quotient;
	char *quotient_s;
	SEXP rquotient_s,rprec,list, list_names;
	
	quotient=(int *)malloc(sizeof(int)*(prec+1));
	for(i=0;i<prec;i++) quotient[i]=0;
	a=(int *)malloc(sizeof(int)*prec);
	b=(int *)malloc(sizeof(int)*prec);
	precesion(quotient,a,b,prec);

	quotient_s =(char *)malloc(sizeof(char)*(prec+3));
	quotient_s[0]='1';quotient_s[1]='.';
	for(i=2;i<prec+2;i++) quotient_s[i] = quotient[i-2]+48;
	quotient_s[prec+2]='\0';
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
		
	free(a);free(b);free(quotient);
	UNPROTECT(4);  
	return(list);	
}

