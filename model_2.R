library(deSolve)

SZUM <- function(t, y, parameters) {
  ya   <- parameters[1]
  ba   <- parameters[2] 
  alfa <- parameters[3] 
  da   <- parameters[4] 
  yr   <- parameters[5]
  br   <- parameters[6]
  kc   <- parameters[7]
  dr   <- parameters[8]
  ka   <- parameters[9]
  kr   <- parameters[10]
  
  at     <- y[1] 
  rt     <- y[2]
  ct     <- y[3]
  
  
  dy    <- c(ya*((alfa + at/ka)/(1 + at/ka)) - kc*at*rt - da*at, 
             yr*(at/kr)/(1 + at/kr) - kc*at*rt + da*ct - dr*rt,
             kc*at*rt - da*ct)
  list(dy)
}
#w zadaniu 3.2 dr zmienic na 0.2 i opisac obserwacje
parameters_SZUM <- c(ya = 250, ba = 5,  alfa = 0.1, da = 1, yr = 50, 
                     br = 10, kc = 200, dr = 0.1, ka = 0.5, kr = 1)
#w zadaniu 3.3 tutaj wstawic te dwa zestawy
inits <- c(at = 0, rt = 0, ct = 0)

dt    <- seq(0,100,0.01)		

simulation <- as.data.frame(lsoda(inits, dt, SZUM, parameters_SZUM))

attach(simulation)

plot(dt,at,
     t = "l",
     col = "blue",
     lwd = 3,
     xlab = "Czas",
     ylab = "Liczba czasteczek",
     ylim = c(0,250))

lines (dt, rt,
       t = "l",
       col = "magenta",
       lwd = 3)

lines (dt, ct,
       t = "l",
       col = "green",
       lwd = 3)

legend(80, 250, legend=c("Aktywator", "Represor", "Produkt"),
       col=c("blue", "magenta", "green"), 
       lty=c(1,1),
       lwd = 3,
       cex=0.8,
       text.font=3, 
       bg='white')

detach(simulation)