# ///////////////////////////////////////////////
# AESOP-Lite Time-of-Flight Analysis: T2 & ToF
# Made by Michelle P
# UCSC 7/224/2023
# ///////////////////////////////////////////////

# NOTES:
# Csv format is --> "tof, pulse_t2"

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# LOAD DATA
df = pd.read_csv("T2_ToFAnalysis_07_24_2023.csv")
df.dropna(axis="columns", inplace=True)

# load dataframe variables
tof = df["tof"]
t2 = df["pulse_t2"]
