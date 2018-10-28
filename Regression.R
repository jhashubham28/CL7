Including Libraries
library("Metrics")
library("lattice")
library("DAAG")
# Loading Dataset
Data <- cars
Data
# Splitting Dataset into training and testing dataset

Training = Data[1:40,]
Testing = Data[41:50,]

# Formation of model for training dataset.

TVm <- lm(dist~speed,data = Training)
TVm

# Model Plotting.

plot(Training$dist~Training$speed,xlab = "speed",ylab = "dist")
abline(TVm)
# Prediction for model for training Data
TV1 <- predict(TVm, Training)
# Prediction for model for training Data
TV2<- predict(TVm, Testing)

# Calculation of Mean Squared Error For Training Dataset

TVTrainMSE <- mse(Training$dist, TV1)
TVTrainMSE


# Calculation of Mean Squared Error For Testing Dataset

TVTestMSE <- mse(Testing$dist, TV2)
TVTestMSE



# Combining all Mean Squared Errors.

trainMSE <- c(TVTrainMSE)
trainMSE

testMSE <- c(TVTestMSE)
testMSE

# Plotting Mean Squared Error for Training and Testing Dataset.

barplot(trainMSE, width = 0.02, xlab = "Data", ylab = "Error", main ="Training Error")
barplot(testMSE, width = 0.02, xlab = "Data", ylab = "Error" ,main = "Testing Error")

# Apply Cross Validation and plot graph for error

model1=cv.lm(Data,(dist~speed),m=2)




