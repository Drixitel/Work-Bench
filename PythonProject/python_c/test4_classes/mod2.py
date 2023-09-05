import numpy as np 
from typing import Union, List
from numpy.typing import ArrayLike

class Bag:
    def __init__(self) -> None:
        self.data: List[ArrayLike] = []
        self.x: int = 3

    def add(self, x: ArrayLike) -> None:
        self.data.append(x)

    def addtwice(self, x: ArrayLike) -> None:
        self.add(x)
        self.add(x)