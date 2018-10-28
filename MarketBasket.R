library(arulesViz)
library(datasets)
data(Groceries)
itemFrequencyPlot(Groceries,topN=20,type="absolute")

rules <-apriori(Groceries, parameter = list(supp=0.001,conf=0.8))

options(digits = 2)
inspect(rules[1:5])

rules <- sort(rules,by="confidence",decreasing=TRUE)

rules <-apriori(Groceries, parameter = list(supp=0.001,conf=0.8,maxlen=3))

print(rules)
subset.matrix<-is.subset(rules,rules)
subset.matrix[lower.tri(subset.matrix,diag = TRUE)]<-NA
redundant<-colSums(subset.matrix,na.rm = T)>=1
rules.pruned<-rules[!redundant]
rules<-rules.pruned

rules <-apriori(Groceries, parameter = list(supp=0.001,conf=0.8),
appearance = list(default="lhs",rhs="whole milk"),control=list(verbose=F))

rules <- sort(rules,by="confidence",decreasing=TRUE)
inspect(rules[1:5])
rules <-apriori(Groceries, parameter = list(supp=0.001,conf=0.15,minlen=2),appearance = list(default="rhs",lhs="whole milk"),
                control=list(verbose=F))
rules <- sort(rules,by="confidence",decreasing=TRUE)
inspect(rules[1:5])