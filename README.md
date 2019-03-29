# sqrtn
An R pacakge to calculate sqrt(n) with very high precision. Currenly, we approximate sqrt(2), sqrt(3), and sqrt(5) only. "sqrtn"" implements dramatically fast. It takes only less than 1 minute to approximate sqrt(2) with 100,000 digits.

# Installation

    #install.packages("devtools")
    library(devtools)
    install_github("xliusufe/sqrtn")

# Usage

   - [x] [sqrtn-manual.pdf](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrtn-manual.pdf) ---------- Details of the usage of the package.
   
   - [x] [sqrt2-approx.pdf](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt2-approx.pdf) ---------- The first one million digits of the square root of 2.
   
    - [x] [sqrt3.md](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt3.md) ---------- The first many digits of the square root of 3.
      
     - [x] [sqrt5.md](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt5.md) ---------- The first many digits of the square root of 5.
   
# Example
    library(sqrtn)

    fit <- sqrtn(100)
    print(fit$sqrtn,quote=FALSE)
    #------------------------
    fit <- sqrtn(100,3)
    print(fit$sqrtn,quote=FALSE)
    #------------------------
    fit <- sqrtn(100,5)
    print(fit$sqrtn,quote=FALSE)    

# Development
This R package is developed by Xu Liu (liu.xu@sufe.edu.cn).
