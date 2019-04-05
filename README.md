# sqrtn
An R pacakge to calculate sqrt(n) with very high precision. "sqrtn"" implements dramatically fast. It takes only less than 30 seconds to approximate sqrt(2) with 100,000 digits. Function sqrtn2() can approximate sqrt(n) for any positive integer, but sqrtn() only for n=2,3,5,6,7,8. The last two or three digits may be incorrect. For seek of safety, it is better to input two or three more to guarantee precision.

# Installation

    #install.packages("devtools")
    library(devtools)
    install_github("xliusufe/sqrtn")

# Usage

   - [x] [sqrtn-manual.pdf](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrtn-manual.pdf) ---------- Details of the usage of the package.
   
   - [x] <font color=red>A web-based calculator is available at</font> [https://xliusufe.shinyapps.io/sqrtn/](https://xliusufe.shinyapps.io/sqrtn/).   
   
   - [x] [sqrt2.md](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt2.md) ---------- The first one hundred thousand digits of the square root of 2.
   
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
    fit <- sqrtn2(100,15)
    print(fit$sqrt2,quote=FALSE)    
    #------------------------
    fit <- sqrtn2(100,17)
    print(fit$sqrt2,quote=FALSE)     

# Development
This R package is developed by Xu Liu (liu.xu@sufe.edu.cn) and and Xiao Zhang.
