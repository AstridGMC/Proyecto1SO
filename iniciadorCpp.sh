#!/bin/bash

g++ -o principalCpp main.cpp -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
