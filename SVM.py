# Linear SVM
import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix
from sklearn import svm
from mlxtend.plotting import plot_decision_regions
import matplotlib.pyplot as plot

# Load Iris Dataset
iris = datasets.load_iris()

# Load Sepal Length and Width in variable x and target variable in y.
X = iris.data[:, :2]
y = iris.target

# SVC with linear kernel
svc = svm.SVC(kernel='linear').fit(X,y)

# LinearSVC (linear kernel)
lin_svc = svm.LinearSVC().fit(X, y)

# SVC with RBF kernel
rbf_svc = svm.SVC(gamma=0.7).fit(X, y)

# SVC with polynomial (degree 4) kernel
poly_svc = svm.SVC(kernel='poly', degree=4).fit(X, y)

# Plotting the model
# Linear Model1
plot_decision_regions(X = X, y = y, clf = svc, legend = 2)
plot.xlabel("Sepal Length", size = 14)
plot.ylabel("Sepal Width", size = 14)
plot.title('SVM(Linear Model)', size = 20)
plot.show()

# Linear Model2
plot_decision_regions(X = X, y = y, clf = lin_svc, legend = 2)
plot.xlabel("Sepal Length", size = 14)
plot.ylabel("Sepal Width", size = 14)
plot.title('Linear_SVM(Linear Model)', size = 20)
plot.show()

# RBF Model
plot_decision_regions(X = X, y = y, clf = rbf_svc, legend = 2)
plot.xlabel("Sepal Length", size = 14)
plot.ylabel("Sepal Width", size = 14)
plot.title('RBF Kernel', size = 20)
plot.show()

# Polynomial SVM

plot_decision_regions(X = X, y = y, clf = poly_svc, legend = 2)
plot.xlabel("Sepal Length", size = 14)
plot.ylabel("Sepal Width", size = 14)
plot.title('Polynomial Kernel', size = 20)
plot.show()

# Making Prediction
XTest = X[106:, :]
yTest = y[106:]

# Evalution Of Linear Model.

l_Pred1 = svc.predict(XTest)
l_Pred2 = svc.predict(X)

l_cm1 = confusion_matrix(yTest,l_Pred1)
l_cr1 = classification_report(yTest,l_Pred1)

l_cm2 = confusion_matrix(y,l_Pred2)
l_cr2 = classification_report(y,l_Pred2)

print("\nEvaluation of Linear SVM on feature Data: \n")
print(l_cm1)
print(l_cr1)

print("\nEvaluation of Linear SVM on Target Data: \n")
print(l_cm2)
print(l_cr2)

# Evalution Of RBF Model.

r_Pred1 = rbf_svc.predict(XTest)
r_Pred2 = rbf_svc.predict(X)

r_cm1 = confusion_matrix(yTest,r_Pred1)
r_cr1 = classification_report(yTest,r_Pred1)

r_cm2 = confusion_matrix(y,r_Pred2)
r_cr2 = classification_report(y,r_Pred2)

print("\nEvaluation of RBF SVM on feature Data: \n")
print(r_cm1)
print(r_cr1)

print("\nEvaluation of RBF SVM on Target Data: \n")
print(r_cm2)
print(r_cr2)

# Evalution Of Polynomial Model.

p_Pred1 = rbf_svc.predict(XTest)
p_Pred2 = rbf_svc.predict(X)

p_cm1 = confusion_matrix(yTest,p_Pred1)
p_cr1 = classification_report(yTest,p_Pred1)

p_cm2 = confusion_matrix(y,p_Pred2)
p_cr2 = classification_report(y,p_Pred2)

print("\nEvaluation of Polynomial SVM on feature Data: \n")
print(p_cm1)
print(p_cr1)

print("\nEvaluation of Polynomial SVM on Target Data: \n")
print(p_cm2)
print(p_cr2)
