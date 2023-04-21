library(deSolve)

NAR <- function(t, y, parameters) {
  gamma_A <- parameters[1]
  b_A     <- parameters[2]
  K_A     <- parameters[3]
  alpha_0 <- parameters[4]
  delta_A <- parameters[5]
  gamma_R <- parameters[6]
  b_R     <- parameters[7]
  K_R     <- parameters[8]
  k_C     <- parameters[9]
  delta_R <- parameters[10]
  
  N_A <- y[1]
  N_R <- y[2]
  N_C <- y[3]
  
  
  dy    <- c(gamma_A * ((alpha_0 + (N_A / K_A)) / (1 + (N_A / K_A))) - k_C * N_A * N_R - delta_A * N_A,
             gamma_R * ((N_A / K_R) / (1 + (N_A / K_R))) - k_C * N_A * N_R + delta_A * N_C - delta_R*N_R,
             k_C * N_A * N_R - delta_A * N_C
             )
  list(dy)
}

parameters_NAR <- c(gamma_A = 250,b_A = 5,K_A = 0.5, alpha_0 = 0.1, delta_A = 1,gamma_R = 50, b_R = 10, K_R = 1, k_C = 200, delta_R = 0.1)
inits <- c(N_A=0, N_R=0, N_C=0)
dt    <- seq(0,500,0.01)			
simulation <- as.data.frame(lsoda(inits, dt, NAR, parameters_NAR))

attach(simulation)
plot(dt, simulation$N_A, type="l", xlab="czas(h)", ylab="liczba cząsteczek",lwd=3,ylim=c(0,200), xlim=c(0,500), col="darkgreen")
lines (dt, simulation$N_R, lwd=3, col="orange")
legend(450, 200, legend=c("A", "R"),
       col=c("darkgreen", "orange"), lty=c(1,1), cex=0.8,
       text.font=4, bg='white')
detach(simulation) 
