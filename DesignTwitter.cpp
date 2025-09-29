// https://leetcode.com/problems/design-twitter/?envType=problem-list-v2&envId=linked-list 
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Tweet {
    int userId;
    int tweetId;
    Tweet* next;
    Tweet(): userId(0), tweetId(0), next(nullptr) {}
    Tweet(int u, int t): userId(u), tweetId(t), next(nullptr) {}
    Tweet(int u, int t, Tweet* n): userId(u), tweetId(t), next(n) {}
};

class Twitter {
private:
    Tweet* head;
    unordered_map<int, unordered_set<int>> followeeList;

public:
    Twitter(): head(nullptr), followeeList({}) {}
    
    void postTweet(int userId, int tweetId) {
        Tweet* newTweet = new Tweet(userId, tweetId, head);
        head = newTweet;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        unordered_set followees = followeeList[userId];

        Tweet* curr = head;
        while (curr) {
            if (curr->userId == userId || followees.count(curr->userId) > 0)
                newsFeed.push_back(curr->tweetId);
            curr = head->next;
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followeeList[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followeeList[followerId].erase(followeeId);
    }
};

int main() {
    Twitter* obj;
    int userId, tweetId, followerId, followeeId;
    vector<int> param_2;

    cout << "Expected: [5] [6 5] [5]" << endl;
    cout << "Result  : ";

    // action 1
    obj = new Twitter();
    
    // action 2
    obj->postTweet(1, 5);

    // action 3
    param_2 = obj->getNewsFeed(1);
    cout << "[";
    for (int feed: param_2) {cout << " " << feed;}
    cout << "]";

    // action 4
    obj->follow(1, 2);

    // action 5
    obj->postTweet(2, 6);

    // action 6
    param_2 = obj->getNewsFeed(1);
    cout << "[";
    for (int feed: param_2) {cout << " " << feed;}
    cout << "]";

    // action 7
    obj->unfollow(1, 2);

    // action 8
    param_2 = obj->getNewsFeed(1);
    cout << "[";
    for (int feed: param_2) {cout << " " << feed;}
    cout << "]";

    return 0;
}
