class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweetsById;
    unordered_map<int, unordered_set<int>> followingById;
    int time;

    Twitter() {
        time = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        if (!tweetsById.count(userId)) {
            tweetsById[userId].reserve(10);
        }
        tweetsById[userId].push_back({time, tweetId});
        time++;
        if (tweetsById[userId].size() > 10) {
            tweetsById[userId].erase(tweetsById[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> recent;

        vector<pair<int, int>> tweets = tweetsById[userId];
        for (const pair<int, int> & t : tweets) {
            recent.push(t);
        }

        for (const int & f : followingById[userId]) {
            tweets = tweetsById[f];
            for (const pair<int, int> & t : tweets) {
                recent.push(t);
            }
        }

        vector<int> res;
        while (!recent.empty() && res.size() < 10) {
            res.push_back(recent.top().second);
            recent.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        unordered_set<int> & following = followingById[followerId];
        if (!following.count(followeeId)) {
            following.insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        unordered_set<int> & following = followingById[followerId];
        if (following.count(followeeId)) {
            following.erase(followeeId);
        }
    }
};
