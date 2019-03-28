sqrtn <- function(prec,n=2){
  if(n<0) stop("n must be a non negative integer!")
  if(prec<0) stop("prec must be a non negative integer!")
  fit2 <- .Call("sqrtn",as.integer(prec), as.integer(n))
  fit <- list(sqrt2=fit2$sqrt2,prec=fit2$prec
              )
  fit
}
