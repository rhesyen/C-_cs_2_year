library(deSolve)
##a
model <- function(t, y, parameters) {
  A  <- parameters[1]
  B  <- parameters[2]
  G  <- parameters[3]
  e  <- parameters[4]
  IKK  <- parameters[5]
  
  Nn     <- y[1]
  Im     <- y[2]
  I      <- y[3]
  
  dy    <- c( A * (1-Nn)/(e +I)- B * (I * Nn)/(G +Nn),
             Nn^2 - Im,
             Im- IKK * ((1-Nn) * I)/(e + I)) 
  
  list(dy)
}

parameters <- c(A = 0.007, B = 954.5, G = 0.029, e = 0.00005, IKK = 0.035)
inits <- c(Nn = 0, Im = 0, I = 0)
dt    <- seq(0,100,0.001)

simulation1 <- as.data.frame(lsoda(inits, dt, model, parameters))

plot(dt, simulation1$Nn, type="l", col="plum", xlab="czas", ylab="", lwd=1.5,ylim=c(0,1), xlim=c(0,30))
lines(dt, simulation1$Im, type="l", col="blue",lwd=1.5)
lines(dt, simulation1$I, type="l", col="green",lwd=1.5)
legend(7,1,legend = c("stężenie aktywnego NF-kB", "mRNA IkB", "IkB"), col =c("plum", "blue", "green"), lty = 1:2, cex = 0.8)

##b

model <- function(t, y, parameters) {
  A  <- parameters[1]
  B  <- parameters[2]
  G  <- parameters[3]
  e  <- parameters[4]
  IKK  <- parameters[5]
  
  Nn     <- y[1]
  Im     <- y[2]
  I      <- y[3]
  
  dy    <- c( A * (1-Nn)/(e +I)- B * (I * Nn)/(G +Nn),
              Nn^2 - Im,
              Im- IKK * ((1-Nn) * I)/(e + I)) 
  
  list(dy)
}

parameters <- c(A = 0.007, B = 954.5, G = 0.029, e = 0.00005, IKK = 0.035)
inits <- c(Nn = 0, Im = 0, I = 0)
dt    <- seq(0,100,0.01)

simulation1 <- as.data.frame(lsoda(inits, dt, model, parameters))

plot(dt * 58.8235294, simulation1$Nn, type="l", col="plum", xlab="czas(min)", ylab="", lwd=1.5,ylim=c(0,1), xlim=c(0,1500))
lines(dt * 58.8235294, simulation1$Im, type="l", col="blue",lwd=1.5)
lines(dt * 58.8235294, simulation1$I, type="l", col="green",lwd=1.5)
legend(100,1,legend = c("stężenie aktywnego NF-kB", "mRNA IkB", "IkB"), col =c("plum", "blue", "green"), lty = 1:2, cex = 0.8)

##c
model <- function(t, y, parameters) {
  A  <- parameters[1]
  B  <- parameters[2]
  G  <- parameters[3]
  e  <- parameters[4]
  IKK  <- parameters[5]
  
  Nn     <- y[1]
  Im     <- y[2]
  I      <- y[3]
  
  dy    <- c( A * (1-Nn)/(e +I)- B * (I * Nn)/(G +Nn),
              Nn^2 - Im,
              Im- IKK * ((1-Nn) * I)/(e + I)) 
  
  list(dy)
}

parameters <- c(A = 0.007, B = 954.5, G = 0.029, e = 0.00005, IKK = 0.035)
parameters2 <- c(A = 0.007, B = 954.5, G = 0.029, e = 0.00005, IKK = 0.105)
parameters3 <- c(A = 0.007, B = 954.5, G = 0.029, e = 0.00005, IKK = 0.175)
inits <- c(Nn = 0, Im = 0, I = 0)
dt    <- seq(0,100,0.001)

simulation1 <- as.data.frame(lsoda(inits, dt, model, parameters))
simulation2 <- as.data.frame(lsoda(inits, dt, model, parameters2))
simulation3 <- as.data.frame(lsoda(inits, dt, model, parameters3))

plot(dt * 58.8235294, simulation1$Nn, type="l", col="plum", xlab="czas(min)", ylab="", lwd=1.5,ylim=c(0,1), xlim=c(0,1500))
lines(dt * 58.8235294, simulation1$Im, type="l", col="blue",lwd=1.5)
lines(dt * 58.8235294, simulation1$I, type="l", col="green",lwd=1.5)
legend(100,1,legend = c("stężenie aktywnego NF-kB", "mRNA IkB", "IkB"), col =c("plum", "blue", "green"), lty = 1:2, cex = 0.8)


plot(dt * 58.8235294, simulation2$Nn, type="l", col="plum", xlab="czas(min)", ylab="", lwd=1.5,ylim=c(0,1), xlim=c(0,1000))
lines(dt * 58.8235294, simulation2$Im, type="l", col="blue",lwd=1.5)
lines(dt * 58.8235294, simulation2$I, type="l", col="green",lwd=1.5)
legend(100,1,legend = c("stężenie aktywnego NF-kB", "mRNA IkB", "IkB"), col =c("plum", "blue", "green"), lty = 1:2, cex = 0.8)


plot(dt * 58.8235294, simulation3$Nn, type="l", col="plum", xlab="czas(min)", ylab="", lwd=1.5,ylim=c(0,1), xlim=c(0,1000))
lines(dt * 58.8235294, simulation3$Im, type="l", col="blue",lwd=1.5)
lines(dt * 58.8235294, simulation3$I, type="l", col="green",lwd=1.5)
legend(100,1,legend = c("stężenie aktywnego NF-kB", "mRNA IkB", "IkB"), col =c("plum", "blue", "green"), lty = 1:2, cex = 0.8)

##d
model <- function(t, y, parameters) {
  A  <- parameters[1]
  B  <- parameters[2]
  G  <- parameters[3]
  e  <- parameters[4]
  IKK  <- parameters[5]
  c <- parameters[6]
  
  Nn     <- y[1]
  Im     <- y[2]
  I      <- y[3]
  
  dy    <- c( A * (1-Nn)/(e +I)- B * (I * Nn)/(G +Nn),
              c + Nn^2 - Im,
              Im- IKK * ((1-Nn) * I)/(e + I)) 
  
  list(dy)
}

parameters <- c(A = 0.007, B = 954.5, G = 0.029, e = 0.00005, IKK = 0.035, c = 0.005)
parameters2 <- c(A = 0.007, B = 954.5, G = 0.029, e = 0.00005, IKK = 0.035, c = 0.02)

inits <- c(Nn = 0, Im = 0, I = 0)
dt    <- seq(0,100,0.001)

simulation1 <- as.data.frame(lsoda(inits, dt, model, parameters))
simulation2 <- as.data.frame(lsoda(inits, dt, model, parameters2))

plot(dt * 58.8235294, simulation1$Nn, type="l", col="plum", xlab="czas(min)", ylab="", lwd=1.5,ylim=c(0,1), xlim=c(0,2500))
lines(dt * 58.8235294, simulation1$Im, type="l", col="blue",lwd=1.5)
lines(dt * 58.8235294, simulation1$I, type="l", col="green",lwd=1.5)
legend(100,1,legend = c("stężenie aktywnego NF-kB", "mRNA IkB", "IkB"), col =c("plum", "blue", "green"), lty = 1:2, cex = 0.8)


plot(dt * 58.8235294, simulation2$Nn, type="l", col="plum", xlab="czas(min)", ylab="", lwd=1.5,ylim=c(0,1), xlim=c(0,1000))
lines(dt * 58.8235294, simulation2$Im, type="l", col="blue",lwd=1.5)
lines(dt * 58.8235294, simulation2$I, type="l", col="green",lwd=1.5)
legend(100,1,legend = c("stężenie aktywnego NF-kB", "mRNA IkB", "IkB"), col =c("plum", "blue", "green"), lty = 1:2, cex = 0.8)
