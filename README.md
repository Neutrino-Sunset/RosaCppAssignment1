# RosaCppAssignment1

## Overview

This application permits the creation of multiple options for a single underlying, and then computes
various values of those options using the Binomial Option Pricing Model.


## Description

The application uses several modules from the coursework example projects, some of which have been modified
as required.


### BinModel02

Used to hold values associated with the Binomial Model. It has had a construtor added so that models with
pre-configured values can be constructed for testing to save having to manually enter them each time.
Basic error handling has been added to GetInputData.


### EurOption

EurOption has been copied from the Options06 module but has been modified extensively.

The original implementation of this class had a method PriceByCRR by computed the option price at n=0. It did
this by computing the option prices for the final nodes and then working backwards to compute the price of node n=0. 
This function has been modified so that it instead returns the price at a specified node.

The methods ComputeReplicationX and ComputeReplicationY have been added which compute the respective replication values.

A Compute method computes the options values for the specified node and stores them so that they can be used later.

An OutputData method writes the option values to the console.

Basic error handling has been added to the data entry functions.


### OptionCollection

This class has a `vector<EurOption>` to maintain a set of options and some member functions to create options either
programmatically or via user input. It also has member functions to compute the values for all options at a specifed
node and to output the resulting computations for all options.

### Helpers

Contains some helper functions used throughout the application.