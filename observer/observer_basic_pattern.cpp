/********************************************************
 OBSERVER PATTERN – CONTEXT PASSING VERSION (C++)

 Key Idea:
 - Subject (Channel) passes itself to update(Channel*)
 - Subscriber always knows WHO sent the notification

 This file demonstrates THREE valid designs:

 1) Single-channel Subscriber
 2) Pure Observer (no channel storage)
 3) Managed Subscriber (multiple channels)

 Teaching Rule:
 "Context passing solves the 'who notified me?' problem."
********************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* Forward declaration */
class Channel;

/* ===================== INTERFACES ===================== */

/*
 Observer Interface
 - Context passing via Channel*
*/
class Isubscriber {
public:
    virtual void update(Channel* channel) = 0;
    virtual ~Isubscriber() {}
};

/*
 Subject Interface
*/
class Ichannel {
public:
    virtual void subscribe(Isubscriber* subscriber) = 0;
    virtual void unSubscribe(Isubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~Ichannel() {}
};

/* ===================== SUBJECT ===================== */

class Channel : public Ichannel {
private:
    vector<Isubscriber*> subscribers;
    string name;
    string latestVideo;

public:
    Channel(const string& name) : name(name) {}

    void subscribe(Isubscriber* subscriber) override {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
            subscribers.push_back(subscriber);
    }

    void unSubscribe(Isubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end())
            subscribers.erase(it);
    }

    void notifySubscribers() override {
        for (Isubscriber* sub : subscribers)
            sub->update(this);  // CONTEXT PASSING
    }

    void uploadVideo(const string& title) {
        latestVideo = title;
        cout << "\n[" << name << "] Uploaded video: " << title << endl;
        notifySubscribers();
    }

    string getVideoData() const {
        return latestVideo;
    }

    string getName() const {
        return name;
    }
};

/* ===================================================== */
/* =============== VARIANT 1 ============================ */
/* Single Channel Subscriber                             */
/* ===================================================== */

/*
 Teaching Point:
 - Subscriber stores ONE channel
 - Context passing still works
 - Slight redundancy, but very clear for beginners
*/
class SingleChannelSubscriber : public Isubscriber {
private:
    string name;
    Channel* channel;

public:
    SingleChannelSubscriber(const string& name, Channel* channel)
        : name(name), channel(channel) {}

    void update(Channel* notifiedChannel) override {
        cout << "[Single] Hey " << name
             << ", new video from "
             << notifiedChannel->getName()
             << ": "
             << notifiedChannel->getVideoData()
             << endl;
    }
};

/* ===================================================== */
/* =============== VARIANT 2 ============================ */
/* Pure Observer Pattern                                 */
/* ===================================================== */

/*
 Teaching Point:
 - Subscriber does NOT store any Channel
 - Fully decoupled
 - Context comes ONLY from update(Channel*)
 - Best for interviews & exams
*/
class PureSubscriber : public Isubscriber {
private:
    string name;

public:
    PureSubscriber(const string& name) : name(name) {}

    void update(Channel* channel) override {
        cout << "[Pure] Hey " << name
             << ", new video from "
             << channel->getName()
             << ": "
             << channel->getVideoData()
             << endl;
    }
};

/* ===================================================== */
/* =============== VARIANT 3 ============================ */
/* Managed Subscriber (Real World)                       */
/* ===================================================== */

/*
 Teaching Point:
 - Subscriber stores MULTIPLE channels
 - Subscriber manages subscriptions
 - Context passing still used for notification
*/
class ManagedSubscriber : public Isubscriber {
private:
    string name;
    vector<Channel*> channels;

public:
    ManagedSubscriber(const string& name) : name(name) {}

    void subscribeTo(Channel* channel) {
        channels.push_back(channel);
        channel->subscribe(this);
    }

    void unSubscribeFrom(Channel* channel) {
        channels.erase(
            remove(channels.begin(), channels.end(), channel),
            channels.end()
        );
        channel->unSubscribe(this);
    }

    void update(Channel* channel) override {
        cout << "[Managed] Hey " << name
             << ", new video from "
             << channel->getName()
             << ": "
             << channel->getVideoData()
             << endl;
    }
};

/* ===================== MAIN ===================== */

int main() {

    Channel tech("TechWorld");
    Channel music("MusicHub");

    /* ---------- VARIANT 1 DEMO ---------- */
    cout << "===== VARIANT 1: Single Channel Subscriber =====\n";
    SingleChannelSubscriber s1("Aditya", &tech);
    SingleChannelSubscriber s2("Yash", &tech);

    tech.subscribe(&s1);
    tech.subscribe(&s2);

    tech.uploadVideo("Observer Pattern Basics");

    /* ---------- VARIANT 2 DEMO ---------- */
    cout << "\n===== VARIANT 2: Pure Observer =====\n";
    PureSubscriber p1("Rohit");

    tech.subscribe(&p1);
    music.subscribe(&p1);

    tech.uploadVideo("Loose Coupling Explained");
    music.uploadVideo("Design Patterns Overview");

    /* ---------- VARIANT 3 DEMO ---------- */
    cout << "\n===== VARIANT 3: Managed Subscriber =====\n";
    ManagedSubscriber m1("Aditya");

    m1.subscribeTo(&tech);
    m1.subscribeTo(&music);

    tech.uploadVideo("Advanced C++ Patterns");
    music.uploadVideo("System Design Podcast");

    cout << "\n--- Unsubscribing from TechWorld ---\n";
    m1.unSubscribeFrom(&tech);

    tech.uploadVideo("Templates Deep Dive");
    music.uploadVideo("Live Coding Session");

    return 0;
}

// Observer pattern defines HOW notifications happen.
// Application design decides WHO manages subscriptions.

// If update() has no parameters → observer does not know the source.
// Passing Subject* to update() is the standard solution.

// Context passing (update(Channel*)) tells the observer WHO notified it.
// All Observer variants can use context passing.
// Pattern = notification, not ownership.