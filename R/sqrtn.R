sqrtn <- function(prec,n=2){
  if(n<0) stop("n must be a non negative integer!")
  if(prec<0) stop("prec must be a non negative integer!")
  if(n==4) fit <- list(sqrt2=2,prec=prec)
  if(n==9) fit <- list(sqrt2=3,prec=prec)
  if(n>9) stop("sqrtn only approximates sqrt(n) with n less than 10 currently.")
  else{
    fit2 <- .Call("sqrtn",as.integer(prec), as.integer(n))
    fit <- list(sqrt2=fit2$sqrt2,prec=fit2$prec)
  }
  fit
}
