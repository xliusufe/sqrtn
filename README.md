# sqrtn
An R pacakge to calculate sqrt(n) with very high precision. Currenly, we approximate sqrt(2) only. "sqrtn"" implements dramatically fast. It takes only less than 1 minute to approximate sqrt(2) with 100,000 digits.

# Installation

    #install.packages("devtools")
    library(devtools)
    install_github("xliusufe/sqrtn")

# Usage

   - [x] [sqrtn-manual.pdf](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrtn-manual.pdf) ---------- Details of the usage of the package.
   
   - [x] [sqrt2.docx](https://github.com/xliusufe/sqrtn/blob/master/inst/sqrt2.docx) ---------- The first one million digits of the square root of 2.
   
# Example
    library(sqrtn)

    fit <- sqrtn(10)
    print(fit$sqrtn,quote=FALSE)
    #------------------------
    fit <- sqrtn(1000)
    print(fit$sqrtn,quote=FALSE)
    

# Development
This R package is developed by Xu Liu (liu.xu@sufe.edu.cn).
