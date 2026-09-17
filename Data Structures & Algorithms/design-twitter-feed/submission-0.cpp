class Twitter {
private:
    int timeStamp;

    struct Tweet {
        int id;
        int time;
        Tweet(int tweetId, int t) : id(tweetId), time(t) {}
    };

    std::unordered_map<int, std::vector<Tweet>> tweets;
    std::unordered_map<int, std::unordered_set<int>> follows;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, timeStamp++));
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int, int>> maxHeap;

        // Ensure user sees their own tweets
        follows[userId].insert(userId);

        // Fetch recent tweets from all followed users
        for (int followeeId : follows[userId]) {
            const auto& userTweets = tweets[followeeId];
            
            for (int i = userTweets.size() - 1; i >= 0 && i >= (int)userTweets.size() - 10; i--) {
                maxHeap.push({userTweets[i].time, userTweets[i].id});
            }
        }

        // Get top 10 most recent tweets
        std::vector<int> result;
        while (!maxHeap.empty() && result.size() < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};
