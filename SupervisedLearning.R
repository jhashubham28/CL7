library("Metrics")
library("lattice")
library("DAAG")

Data <- read.csv("C:/Users/Jha's/Downloads/Advertising.csv")
Data
Training = Data[1:140,]
Training
Testing = Data[141:200,]
Testing

TVm <- lm(sales~TV,data = Training)
TVm
Radiom <- lm(sales~radio,data=Training)
Radiom

newspaperm =lm(sales~newspaper,data=Training)
newspaperm

plot(Training$sales~Training$TV,xlab="TV",ylab="Sales")
abline(TVm)

plot(Training$sales~Training$newspaper,xlab="Newspaper",ylab="Sales")
abline(newspaperm)

plot(Training$sales~Training$radio,xlab="Radio",ylab="Sales")
abline(Radiom)

TV1<- predict(TVm,Training)
Radio1<-predict(Radiom,Training)
newspaper1 <- predict(newspaperm,Training)

TV2<- predict(TVm,Testing)
Radio2<-predict(Radiom,Testing)
newspaper2 <- predict(newspaperm,Testing)

TVTrainMSE <- mse(Training$sales,TV1)
TVTrainMSE

RadioTrainMSE <-mse(Training$sales,Radio1)
RadioTrainMSE

newspapertrainmse <- mse(Training$sales,newspaper1)
newspapertrainmse

TVTestMSE <- mse(Testing$sales,TV2)
TVTestMSE

RadioTestMSE <-mse(Testing$sales,Radio2)
RadioTestMSE

newspapertestmse <- mse(Testing$sales,newspaper2)
newspapertestmse

trainMSE <- c(TVTrainMSE,RadioTrainMSE,newspapertrainmse)
trainMSE

testMSE <- c(TVTestMSE,RadioTestMSE,newspapertestmse)
testMSE

barplot(trainMSE,width=0.02,xlab="Data",ylab="Error",main="Training Error")
barplot(testMSE,width=0.02,xlab="Data",ylab="Error",main="Testing Error")

model1=cv.lm(Data,(sales~TV),m=10)ik




