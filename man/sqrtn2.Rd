\name{sqrtn2}
\alias{sqrtn2}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
An R pacakge to calculate \eqn{\sqrt{n}} with very high precision.
}
\description{
Calculate \eqn{\sqrt{n}} with very high precision.
}
\usage{
sqrtn2(prec,n=2)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{prec}{A non negative integer, which is the precision you want.
}
  \item{n}{A non negative integer, the default is \eqn{2}.
}
}

\value{
  \item{sqrt2}{The digits of the square root of \eqn{n}, which is a string.}
  \item{prec}{ The input precision.}
}
\author{
Xiao Zhang and Xu Liu.
}

\examples{
#Example 1
fit <- sqrtn2(100)
print(fit$sqrt2,quote=FALSE)

#Example 2
fit <- sqrtn2(100,3)
print(fit$sqrt2,quote=FALSE)

#Example 3
fit <- sqrtn2(100,15)
print(fit$sqrt2,quote=FALSE)

#Example 4
fit <- sqrtn2(100,17)
print(fit$sqrt2,quote=FALSE)
}

