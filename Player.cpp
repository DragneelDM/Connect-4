class Player {
private:
    std::string name;
    std::string color;

public:
    Player(const std::string& playerName, const std::string& playerColor) : name(playerName), color(playerColor) {}
    
    std::string getName() const {
        return name;
    }
    
    std::string getColor() const {
        return color;
    }
};
