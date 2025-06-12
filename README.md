# Husky Visualization: Intelligent Data Visualization Recommendation System

Husky Visualization is a distributed data visualization recommendation system that automatically generates and suggests appropriate visualizations based on data characteristics and statistical analysis. The system combines backend processing power with an intuitive frontend interface to help users explore and understand their data through meaningful visual representations.

The system consists of three main components:
- A C++ backend that handles data processing, statistical analysis, and visualization recommendations using the Husky distributed computing framework
- An Express.js middleware layer that facilitates communication between frontend and backend
- A Vue.js frontend that provides an interactive interface for users to explore and select visualizations

Key features include:
- Automatic chart type suggestion based on data characteristics
- Statistical analysis including variance, mean, sum, max/min calculations
- Support for distributed data processing
- Real-time visualization updates
- Interactive attribute selection and filtering
- Support for multiple chart types including bar, line and point charts
- MongoDB integration for data storage and retrieval

## Repository Structure
```
.
├── backend/                 # C++ backend implementation
│   ├── app/                # Main application code and Thrift interface
│   ├── core/               # Core business logic components
│   │   ├── channel/        # Data processing and visualization channels
│   │   ├── common/         # Shared utilities and constants
│   │   └── dataloader/     # Data loading and schema management
│   └── test/              # Comprehensive test suite
├── backend-express-es6/    # Express.js middleware layer
│   ├── src/               # Source code for API endpoints and controllers
│   └── controller/        # Business logic controllers
└── frontend-vue/          # Vue.js frontend application
    ├── src/              # Vue application source code
    ├── test/             # Frontend unit and e2e tests
    └── mock-server/      # Mock data for development
```

## Usage Instructions
### Prerequisites
- C++ compiler with C++14 support
- CMake 3.0 or higher
- Node.js 12.x or higher
- MongoDB 4.x
- Husky distributed computing framework
- Boost libraries
- Thrift RPC framework

### Installation

#### Backend (C++)
```bash
# MacOS
brew install cmake boost thrift mongodb

# Linux
sudo apt-get install cmake libboost-all-dev thrift-compiler mongodb

# Build backend
cd backend
mkdir build && cd build
cmake ..
make
```

#### Middleware (Express.js)
```bash
cd backend-express-es6
npm install
npm run build
```

#### Frontend (Vue.js)
```bash
cd frontend-vue
npm install
```

### Quick Start
1. Start MongoDB:
```bash
mongod --dbpath /path/to/data
```

2. Start the backend server:
```bash
cd backend/build
./Server
```

3. Start the Express middleware:
```bash
cd backend-express-es6
npm start
```

4. Start the frontend development server:
```bash
cd frontend-vue
npm run dev
```

### More Detailed Examples
1. Loading data and generating visualizations:
```cpp
// Initialize the visualization system
husky::visualization::Controller::init_visualization();

// Select an attribute to analyze
std::string attribute = "Weight_in_lbs";
std::vector<husky::visualization::SuggestionObject> suggestions;
Controller::init_visualization(suggestions, attribute);
```

2. Using the frontend interface:
```javascript
// Select an attribute for visualization
this.$http.post('/api/selectAttribute', {
  attribute: 'Weight_in_lbs'
}).then(response => {
  this.suggestions = response.data;
});
```

### Troubleshooting
1. Backend build issues:
- Error: "Boost not found"
  ```bash
  export BOOST_ROOT=/path/to/boost
  cmake ..
  ```

2. MongoDB connection issues:
- Check MongoDB is running:
  ```bash
  ps aux | grep mongod
  ```
- Verify connection string in configuration

## Data Flow
The system processes data through multiple channels to generate appropriate visualizations.

```
[Raw Data] -> [DataLoader] -> [GenerateChannel] -> [ChartTypeChannel] -> [AggregateChannel]
     |              |              |                       |                    |
     v              v              v                       v                    v
[MongoDB] -> [Schema Validation] -> [Statistical Analysis] -> [Chart Selection] -> [Frontend]
```

Key component interactions:
1. DataLoader reads data from MongoDB and validates against schema
2. GenerateChannel creates initial visualization suggestions
3. ChartTypeChannel determines appropriate chart types
4. AggregateChannel performs statistical aggregations
5. ProcessRawDataChannel handles raw data transformations
6. ProcessAggregateDataChannel processes aggregated results
7. Frontend receives and displays visualization recommendations