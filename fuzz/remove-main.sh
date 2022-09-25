#!/bin/bash
pcregrep -M -v 'int main\(\)[\s*]{[\s\S]*}' ../main.c > no-main.c