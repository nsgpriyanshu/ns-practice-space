
---

### 🧠 Now, let’s understand the code step by step:

---

## **1. Overview**

This C program is a **Flight Network Simulation System**.

It models **10 major Indian airports** and allows the user to:

1. View all available airports
2. View the **flight connectivity network** (Adjacency Matrix)
3. Find the **shortest route (minimum distance)** between two airports using **Dijkstra’s Algorithm**

---

## **2. Data Structure Used**

### **Adjacency Matrix**

```c
int flightNetwork[MAX][MAX];
```

This matrix represents distances between airports.

* `flightNetwork[i][j] = distance` (if there’s a direct flight)
* `flightNetwork[i][j] = 0` (if no direct flight exists)

For example:

```
flightNetwork[Delhi][Mumbai] = 1400
flightNetwork[Mumbai][Delhi] = 1400
flightNetwork[Delhi][Kolkata] = 1300
```

---

## **3. Airport Names**

```c
char airports[MAX][20] = {
    "Delhi", "Mumbai", "Bengaluru", "Chennai", "Hyderabad",
    "Kolkata", "Ahmedabad", "Pune", "Goa", "Chandigarh"
};
```

These are stored as strings, and each airport’s position in the array corresponds to its matrix index.

---

## **4. Showing the List of Airports**

Function:

```c
void showAirports()
```

* Simply loops through the airport array.
* Displays the list with index numbers.
* Used when user chooses option `1`.

---

## **5. Showing the Flight Network**

Function:

```c
void showFlightNetwork()
```

* Prints the **adjacency matrix** in a well-formatted table.
* Each row and column represents an airport.
* `0` means no direct flight.

---

## **6. Finding Airport Index**

Function:

```c
int getAirportIndex(char *name)
```

* Searches the `airports` array for a matching name.
* Returns its index (0–9) if found.
* Returns `-1` if airport not found.

Used to translate user input (like “Delhi”) into internal index numbers.

---

## **7. Shortest Route Algorithm**

Function:

```c
void findShortestRoute()
```

* Asks user for source and destination airport names.
* Uses `getAirportIndex()` to find their indices.
* If either name is invalid, prints an error.
* Then runs **Dijkstra’s Algorithm** to find the shortest path.

---

### **How Dijkstra Works Here**

It maintains:

```c
int dist[MAX];
int visited[MAX];
int prev[MAX];
```

* `dist[i]`: current shortest known distance from source to airport `i`
* `visited[i]`: whether the airport has been finalized
* `prev[i]`: the previous airport in the shortest route

The algorithm:

1. Initialize all distances to infinity.
2. Start from the source airport.
3. At each step, choose the **unvisited airport** with **minimum distance**.
4. Update distances for all its connected airports.
5. Continue until the destination is reached.

Finally, `prev[]` is used to **retrace the shortest path** and display it.

---

### **Example**

If user chooses:

```
Source: Delhi
Destination: Chennai
```

Program finds the minimum total distance using all available routes (direct or via connecting airports).

---

## **8. Menu System**

The main loop:

```c
while (1) {
    printf(...);
    scanf("%d", &choice);
    switch(choice) {
        case 1: showAirports(); break;
        case 2: showFlightNetwork(); break;
        case 3: findShortestRoute(); break;
        case 4: exit(0);
        default: printf("Invalid choice!\n");
    }
}
```

* Keeps repeating until the user chooses `Exit (4)`.
* Ensures interactive operation in console.

---

## **9. `int main()` (at the end)**

```c
int main() {
    initializeFlightNetwork();
    while (1) { ... }
    return 0;
}
```

* Calls a setup function to **initialize the adjacency matrix** with distances.
* Then enters the **menu loop**.
* User keeps interacting until exiting manually.

---

## ✅ **Summary of Major Functions**

| Function                    | Purpose                                            |
| --------------------------- | -------------------------------------------------- |
| `initializeFlightNetwork()` | Sets up the flight distances between airports      |
| `showAirports()`            | Displays all available airports                    |
| `showFlightNetwork()`       | Displays the adjacency matrix                      |
| `getAirportIndex()`         | Finds the index of an airport by name              |
| `findShortestRoute()`       | Finds and prints the shortest route using Dijkstra |
| `main()`                    | Controls program flow (menu-based)                 |

---

