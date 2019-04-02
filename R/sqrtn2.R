sqrtn2 <- function(prec,n=2){
  if(n<1) stop("n must be a positive integer!")
  if(prec<0) stop("prec must be a positive integer!")
  if(prec==0) fit <- list(sqrt2=as.integer(sqrt(n)),prec=prec)
  else fit <- .Call("sqrtn2",as.integer(prec), as.integer(n))
  fit
}
