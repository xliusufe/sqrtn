# sqrtn
An R pacakge to calculate sqrt(n) with very high precision. Currenly, we approximate sqrt(n) with n<10, that is, sqrt(2), sqrt(3), sqrt(5), sqrt(6), sqrt(7), and sqrt(8) only. "sqrtn"" implements dramatically fast. It takes only less than 1 minute to approximate sqrt(2) with 100,000 digits.

# Installation

    #install.packages("devtools")
    library(devtools)
    install_github("xliusufe/sqrtn")

# Usage

   - [x] [sqrtn-manual.pdf](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrtn-manual.pdf) ---------- Details of the usage of the package.
   
   - [x] [sqrt2-approx.pdf](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt2-approx.pdf) ---------- The first one million digits of the square root of 2.
   
   - [x] [sqrt3.md](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt3.md) ---------- The first many digits of the square root of 3.
      
   - [x] [sqrt5.md](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt5.md) ---------- The first many digits of the square root of 5.
 
   - [x] [sqrt6.md](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt6.md) ---------- The first many digits of the square root of 6.
   
   - [x] [sqrt7.md](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt7.md) ---------- The first many digits of the square root of 7.
   
   - [x] [sqrt8.md](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt8.md) ---------- The first many digits of the square root of 8.
   
# Example
    library(sqrtn)

    fit <- sqrtn(100)
    print(fit$sqrt2,quote=FALSE)
    #------------------------
    fit <- sqrtn(100,3)
    print(fit$sqrt2,quote=FALSE)
    #------------------------
    fit <- sqrtn(100,5)
    print(fit$sqrt2,quote=FALSE)    
    #------------------------
    fit <- sqrtn(100,7)
    print(fit$sqrt2,quote=FALSE)     

# Development
This R package is developed by Xu Liu (liu.xu@sufe.edu.cn).
