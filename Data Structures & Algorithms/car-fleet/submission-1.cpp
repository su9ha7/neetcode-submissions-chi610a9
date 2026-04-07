
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);

        for (int i = 0; i < n; i++) {
            // CRITICAL: Use (double) for precision!
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }

        // CRITICAL: Sort by Position DESCENDING (Closest to target first)
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        int fleetCount = 0;
        double currentFleetTime = 0.0;

        for (int i = 0; i < n; i++) {
            // If this car takes MORE time than the fleet in front
            if (cars[i].second > currentFleetTime) {
                // It's too slow to catch up! It starts a NEW fleet.
                fleetCount++;
                currentFleetTime = cars[i].second;
            }
            // Else: cars[i].second <= currentFleetTime
            // It catches up and becomes part of the fleet in front.
        }

        return fleetCount;
    }
};