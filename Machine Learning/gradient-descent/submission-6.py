class Solution:
    def get_minimizer(self, iterations: int, learning_rate: float, init: int) -> float:
        x= init
        for _ in range(iterations) :
            gradient =2*x
            x = x-(gradient*learning_rate)


        return round(x,5)

    