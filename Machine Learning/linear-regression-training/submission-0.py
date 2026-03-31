import numpy as np
from numpy.typing import NDArray


class Solution:
    def get_derivative(self, model_prediction: NDArray[np.float64], ground_truth: NDArray[np.float64], N: int, X: NDArray[np.float64], desired_weight: int) -> float:
        # note that N is just len(X)
        return -2 * np.dot(ground_truth - model_prediction, X[:, desired_weight]) / N

    def get_model_prediction(self, X: NDArray[np.float64], weights: NDArray[np.float64]) -> NDArray[np.float64]:
        return np.squeeze(np.matmul(X, weights))

    learning_rate = 0.01

    def train_model(
        self, 
        X: NDArray[np.float64], 
        Y: NDArray[np.float64], 
        num_iterations: int, 
        initial_weights: NDArray[np.float64]
    ) -> NDArray[np.float64]:

        # you will need to call get_derivative() for each weight
        # and update each one separately based on the learning rate!
        # return np.round(your_answer, 5)
        weights = np.array(initial_weights)
        N = len(X)

        for _ in range(num_iterations):
            # 1. Get current predictions for the entire dataset
            predictions = self.get_model_prediction(X, weights)
            
            # 2. Update each of the 3 weights separately
            # We use a temporary copy to ensure updates don't mess with the current iteration's math
            new_weights = np.zeros(3)
            for i in range(3):
                derivative = self.get_derivative(predictions, Y, N, X, i)
                new_weights[i] = weights[i] - (self.learning_rate * derivative)
            
            weights = new_weights

        return np.round(weights, 5)