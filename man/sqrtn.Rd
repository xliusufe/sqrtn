\name{sqrtn}
\alias{sqrtn}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
An R pacakge to calculate \eqn{\sqrt{n}} with very high precision.
}
\description{
Calculate \eqn{\sqrt{n}} with very high precision. Currenly, we approximate \eqn{\sqrt{n}} with \eqn{n<10}, that is, \eqn{\sqrt{2}}, \eqn{\sqrt{3}}, \eqn{\sqrt{5}}, , \eqn{\sqrt{6}}, , \eqn{\sqrt{7}} and \eqn{\sqrt{8}} only. "sqrtn"" implements dramatically fast. It takes only \code{29} seconds to approximate \eqn{\sqrt{2}} with \code{100,000} digits.
}
\usage{
sqrtn(prec,n=2)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{prec}{A non negative integer, which is the precision you want.
}
  \item{n}{A non negative integer, the default is \eqn{2}. Currently, we can only approximate \eqn{\sqrt{2}}.
}
}

\value{
  \item{sqrtn}{The digits of the square root of \eqn{n}, which is a string.}
  \item{prec}{ The input precision.}
}
\author{
Xu Liu
}

\examples{
#Example 1
fit <- sqrtn(100)
print(fit$sqrt2,quote=FALSE)

#Example 2
fit <- sqrtn(100,3)
print(fit$sqrt2,quote=FALSE)

#Example 3
fit <- sqrtn(100,5)
print(fit$sqrt2,quote=FALSE)

#Example 4
fit <- sqrtn(100,7)
print(fit$sqrt2,quote=FALSE)
}

