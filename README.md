# Bus Reservation System for Costa Rica 🚍

The Bus Reservation System is a terminal-based application written in C that modernizes ticket purchasing for Costa Rica's public transportation. It addresses current challenges by providing an efficient digital booking solution.

## Key Features ✨

- **User Authentication** 🔒
  - Secure login/signup system

- **Route Management** 🗺️
  - 6 major intercity routes
  - Current pricing (₡)

- **Smart Scheduling** ⏰
  - Route-specific schedules
  - Day/time selection (e.g., "Monday at 1:00 PM")

- **Booking System** 💳
  - Variable ticket quantities
  - Multiple payment methods
  - Price calculation

- **Digital Receipts** 🧾
  - Detailed booking confirmation
  - QR code for validation
  - Transaction history

## Enhanced Workflow 🔄

1. **Authentication** → 2. **Route Selection** → 3. **Schedule Choice** → 4. **Ticket Quantity** → 5. **Payment** → 6. **Receipt**

## Tree Structure of Execution Path
```mermaid
graph TD
    A[Authentication Menu] --> B{User Choice}
    B -->|1| C[Login]
    B -->|2| D[Sign Up]
    B -->|3| E[Exit]
    C --> F[Main System]
    D --> C
    F --> G[Route Selection]
    G --> H[Schedule Selection]
    H --> I[Ticket Quantity]
    I --> J[Payment Processing]
    J --> K[Receipt Generation]
    K --> L[Exit]


