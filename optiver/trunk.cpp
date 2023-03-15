// 1. Truck Positions
// A logistics company has a central software solution to track the
// position of their trucks. Different applications are interested in
// different trucks. To save bandwidth the company wants to have a
// central subscriber for each local office. This service will thein be used
// by the applications in the office to get position updates.
// Your task is to implement the Subscriber class. The subscriber can
// request information from the central server by providing the ID fora
// truck. The server will return the current position and will afterward15
// send position updates as differences as they become availaable
// When a client subscribes to a truck the subscriber should return the
// current truck position. Additionally the client can request an update.
// In that case the client should receive all the updates for all trucks since
// it last requested an update. It is important that all updates arrive in
// the same order as they were initially sent out. Truck positions are
// represented in x and y coordinates.
// Have a look at the provided source code to undersstand which inputs
// are provided and which outputs are expected for the Subscriber claISS.
// Also be aware that you can call the SubscribeTo7Truck function of
// the IServer interface.
// Class Description
// Complete the Subscriber class in the editor below. Apart from its
// constructor, the class has three methods: ProcessUpdate
// ubscribeToTruck and GetUpdates
// The ProcessUpdate method takes the following parameters:
// positionDelta: describes the movement of a truck
// The Subscribe To Truck method takes the following parameters:
// truckld: an integer describing which truck to subscribe to
// clientld: an integer describing which client is subscribing toa
// truck
// Subscribe ToTruck returns:
// TruckPosition: the current position of the the truck with id
// truckld


// sample input:
// 1
// 2 3
// U 0 1.5 2.5
// S 0 0
// U 0 1 2
// U 0 -0.5 -0.5
// S 1 0
// R 0
// U 0 1 1
// R 1
// Sample Output
// S 0 0 3.5 5.5
// S 1 0 4 7
// U 0 1 2
// U 0 -0.5 -0.5
// U 1 1 1

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using ClientId = uint32_t;
using TruckId = uint32_t;

struct TruckPosition
{
    double X;
    double Y;
};

struct TruckPositionDelta
{
    TruckId mTruckId;
    double DeltaX;
    double DeltaY;
};

class IServer
{
public:
    virtual ~IServer() {}
    virtual TruckPosition SubscribeToTruck(TruckId) = 0;
};

class ISubscriber
{
public:
    virtual ~ISubscriber() {}

    // Called by server after initial subscription
    virtual void ProcessUpdate(const TruckPositionDelta&) = 0;

    // Called by clients
    virtual TruckPosition SubscribeToTruck(TruckId, ClientId) = 0;
    virtual std::vector<TruckPositionDelta> GetUpdates(ClientId) = 0;
};

class Subscriber : public ISubscriber
{
public:
    Subscriber(IServer& server) : mServer(server) {}

    void ProcessUpdate(const TruckPositionDelta& delta) override {
        for (auto& client : mClientUpdates)
        {
            for(auto& truck : mClientTruck[client.first])
            {
                if(truck == delta.mTruckId)
                {
                    client.second.push_back(delta);
                }
            } 
        }
    }

    TruckPosition SubscribeToTruck(TruckId id, ClientId cid) override { 

        if(mClientTruck.find(cid) == mClientTruck.end())
        {
            mClientTruck.insert({cid, std::vector<TruckId>()});
            mClientUpdates.insert({cid, std::vector<TruckPositionDelta>()});

        }
        mClientTruck[cid].push_back(id);
        
        return mServer.SubscribeToTruck(id);

    }

    std::vector<TruckPositionDelta> GetUpdates(ClientId cid) override { 
        std::vector<TruckPositionDelta > updates = mClientUpdates[cid];
        mClientUpdates[cid].clear();
        return updates;
    }

private:
    IServer& mServer;
    std::unordered_map<ClientId, std::vector<TruckPositionDelta>> mClientUpdates;
    std::unordered_map<ClientId, std::vector<TruckId>> mClientTruck;
};

class Server : public IServer
{
public:
    TruckPosition SubscribeToTruck(TruckId id) override
    {
        mRegisteredTrucks.insert(id);
        return mCurrentPos.at(id);
    }

    void AddPosition(TruckId id, TruckPosition pos)
    {
        mCurrentPos.insert({id, pos});
    }

    void OnUpdate(Subscriber& subscriber, const TruckPositionDelta& delta)
    {
        if (mRegisteredTrucks.find(delta.mTruckId) != mRegisteredTrucks.end())
        {
            subscriber.ProcessUpdate(delta);
        }
        auto& pos = mCurrentPos.at(delta.mTruckId);
        pos.X += delta.DeltaX;
        pos.Y += delta.DeltaY;
    }

private:
    std::unordered_set<TruckId> mRegisteredTrucks;
    std::unordered_map<TruckId, TruckPosition> mCurrentPos;
};

class Client
{
public:
    Client(ClientId id, ISubscriber& subscriber) : mId(id), mSubscriber(subscriber) {}

    void Subscribe(TruckId truckId)
    {
        TruckPosition pos = mSubscriber.SubscribeToTruck(truckId, mId);
        std::cout << "S " << mId << " " << truckId << " " << pos.X << " " << pos.Y << std::endl;
    }

    void RequestUpdate()
    {
        std::vector<TruckPositionDelta> updates = mSubscriber.GetUpdates(mId);
        for (const TruckPositionDelta& delta : updates)
        {
            std::cout << "U " << mId << " " << delta.mTruckId << " " << delta.DeltaX << " " << delta.DeltaY << std::endl;
        }
    }
private:
    ClientId mId;
    ISubscriber& mSubscriber;
};

std::vector<std::string> split(const std::string& input)
{
    std::vector<std::string> result;
    std::stringstream stringStream (input);
    std::string item;

    while (std::getline(stringStream, item, ' '))
        result.push_back(item);

    return result;
}

int main()
{
    Server server;
    Subscriber subscriber(server);
    std::vector<Client> clients;

    std::string input;

    // Read number of trucks
    std::getline(std::cin, input);
    uint32_t numTrucks = std::stoi(input);
    for (uint32_t i = 0; i < numTrucks; i++)
    {
        std::getline(std::cin, input);
        std::vector<std::string> position = split(input);
        server.AddPosition(i, {std::stod(position[0]), std::stod(position[1])});
    }

    while(std::getline(std::cin, input))
    {
        std::vector<std::string> command = split(input);
        switch(command[0][0])
        {
        case 'S':
            {
                uint32_t clientId = std::stoi(command[1]);
                if (clientId >= clients.size())
                {
                    clients.push_back(Client(clientId, subscriber));
                }
                clients.at(clientId).Subscribe(std::stoi(command[2]));
            }
            break;
        case 'U':
            server.OnUpdate(subscriber, {static_cast<TruckId>(std::stoi(command[1])), std::stod(command[2]), std::stod(command[3])});
            break;
        case 'R':
            clients.at(std::stoi(command[1])).RequestUpdate();
            break;
        default:
            throw std::runtime_error("Invalid input");
        }
    }

    return 0;
}



