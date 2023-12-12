#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class Planner {
private:
    std::string Material;
    std::string Wing_type;
    std::string Takeoff;
    double Weight;
    std::string Manufacturer;
    std::string Model;

public:
    // Default constructor
    Planner() : Weight(0.0) {
        Material = "";
        Wing_type = "";
        Takeoff = "";
        Manufacturer = "";
        Model = "";
    }

    // Parameterized constructor
    Planner(std::string material, std::string wingType, std::string takeoff,
        double weight, std::string manufacturer, std::string model)
        : Material(material), Wing_type(wingType), Takeoff(takeoff),
        Weight(weight), Manufacturer(manufacturer), Model(model) {}

    // Destructor
    ~Planner() {
        std::cout << "Destructor called for " << Model << std::endl;
    }

    // Copy constructor
    Planner(const Planner& other)
        : Material(other.Material), Wing_type(other.Wing_type),
        Takeoff(other.Takeoff), Weight(other.Weight),
        Manufacturer(other.Manufacturer), Model(other.Model) {}

    // Move constructor
    Planner(Planner&& other) noexcept
        : Material(std::move(other.Material)), Wing_type(std::move(other.Wing_type)),
        Takeoff(std::move(other.Takeoff)), Weight(other.Weight),
        Manufacturer(std::move(other.Manufacturer)), Model(std::move(other.Model)) {
        other.Weight = 0.0;  // Reset weight for the moved object
    }

    // Copy assignment operator
    Planner& operator=(const Planner& other) {
        if (this != &other) {
            Material = other.Material;
            Wing_type = other.Wing_type;
            Takeoff = other.Takeoff;
            Weight = other.Weight;
            Manufacturer = other.Manufacturer;
            Model = other.Model;
        }
        return *this;
    }

    // Move assignment operator
    Planner& operator=(Planner&& other) noexcept {
        if (this != &other) {
            Material = std::move(other.Material);
            Wing_type = std::move(other.Wing_type);
            Takeoff = std::move(other.Takeoff);
            Weight = other.Weight;
            Manufacturer = std::move(other.Manufacturer);
            Model = std::move(other.Model);
            other.Weight = 0.0;  // Reset weight for the moved object
        }
        return *this;
    }

    // Getters
    std::string getMaterial() const {
        return Material;
    }

    std::string getWingType() const {
        return Wing_type;
    }

    std::string getTakeoff() const {
        return Takeoff;
    }

    double getWeight() const {
        return Weight;
    }

    std::string getManufacturer() const {
        return Manufacturer;
    }

    std::string getModel() const {
        return Model;
    }

    // Setters
    void setMaterial(const std::string& material) {
        Material = material;
    }

    void setWingType(const std::string& wingType) {
        Wing_type = wingType;
    }

    void setTakeoff(const std::string& takeoff) {
        Takeoff = takeoff;
    }

    void setWeight(double weight) {
        Weight = weight;
    }

    void setManufacturer(const std::string& manufacturer) {
        Manufacturer = manufacturer;
    }

    void setModel(const std::string& model) {
        Model = model;
    }

    // Display method
    void display() const {
        std::cout << "Model: " << Model << ", Material: " << Material
            << ", Wing Type: " << Wing_type << ", Takeoff: " << Takeoff
            << ", Weight: " << Weight << ", Manufacturer: " << Manufacturer << std::endl;
    }

    // Method to compare Planners based on weight (for sorting)
    static bool compareByWeight(const Planner& a, const Planner& b) {
        return a.Weight > b.Weight;
    }
};

int main() {
    // Create a list to store Planner objects
    std::list<Planner> planners;

    // Prompt the user to input 3 objects
    for (int i = 0; i < 3; ++i) {
        std::string material, wingType, takeoff, manufacturer, model;
        double weight;

        std::cout << "Enter Planner details for object " << i + 1 << std::endl;
        std::cout << "Material: ";
        std::cin >> material;
        std::cout << "Wing Type: ";
        std::cin >> wingType;
        std::cout << "Takeoff: ";
        std::cin >> takeoff;
        std::cout << "Weight: ";
        std::cin >> weight;
        std::cout << "Manufacturer: ";
        std::cin >> manufacturer;
        std::cout << "Model: ";
        std::cin >> model;

        planners.emplace_back(material, wingType, takeoff, weight, manufacturer, model);
    }

    // Print the obtained data in table format, sorting by weight in reverse order
    std::cout << "\nPlanner Data (Sorted by Weight in Reverse Order):\n";
    planners.sort(Planner::compareByWeight);

    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "| Model      | Material   | Wing Type  | Takeoff  | Weight | Manufacturer | \n";
    std::cout << "-------------------------------------------------------------------\n";

    for (const auto& planner : planners) {
        planner.display();
        std::cout << "-------------------------------------------------------------------\n";
    }

    // Delete all data from the list using the appropriate methods (destructor will be called for each object)

    return 0;
}
