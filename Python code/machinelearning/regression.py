import pandas as pd
import quandl

#each column e.g. "Open" is a "feature"
df = quandl.get('WIKI/GOOGL')
df = df[['Adj. Open','Adj. High','Adj. Low','Adj. Close','Adj. Volume',]]
df['HL_PCT'] = (df['Adj. High'] - df['Adj. Close']) / df['Adj. Close'] * 100.0  #volatility
df['PCT_change'] = (df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open'] * 100.0

df = df[['Adj. Close', 'HL_PCT', 'PCT_change', 'Adj. Volume']]


print(df.head())

#http://www.astroml.org/sklearn_tutorial/general_concepts.html

#Machine learning can be broken into two broad regimes: supervised learning and unsupervised learning.
# We’ll introduce these concepts here, and discuss them in more detail below.

#In Supervised Learning, we have a dataset consisting of both features and labels.
# The task is to construct an estimator which is able to predict the label of an object given the set of features.
# A relatively simple example is predicting the species of iris given a set of measurements of its flower.
# This is a relatively simple task. Some more complicated examples are:

#given a multicolor image of an object through a telescope, determine whether that object is a star, a quasar,
# or a galaxy.
#given a photograph of a person, identify the person in the photo.
#given a list of movies a person has watched and their personal rating of the movie, recommend a list of movies they
# would like (A famous example is the Netflix Prize).
#What these tasks have in common is that there is one or more unknown quantities associated with the object which needs
# to be determined from other observed quantities. Supervised learning is further broken down into two categories,
# classification and regression. In classification, the label is discrete, while in regression, the label is
# continuous. For example, in astronomy, the task of determining whether an object is a star, a galaxy, or a quasar is
# a classification problem: the label is from three distinct categories. On the other hand, we might wish to determine
# the age of an object based on such observations: this would be a regression problem: the label (age) is a continuous
# quantity.