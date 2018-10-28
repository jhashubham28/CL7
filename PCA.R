data(iris)
iris

var(iris$Petal.Width)
virginica=iris[iris$Species=='virginica',]
virginica

virginica.sl=virginica$Sepal.Length
virginica.sl

mean(virginica.sl)
median(virginica.sl)
var(virginica.sl)
sd(virginica.sl)

log.ir<-log(iris[,1:4])
log.ir
ir.species<-iris[,5]
ir.species

ir.pca<-prcomp(log.ir,center = TRUE,scale.=TRUE)
print(ir.pca)

plot(ir.pca, type="1")
summary(ir.pca)

predict(ir.pca,newdata = tail(log.ir, 2))
biplot(ir.pca)


Data1=iris[1:4]
Data1

Fun<-princomp(Data1)
summary(Fun)

plot(Fun)
screeplot(Fun,type="line",main="Scree plot")
biplot(Fun)