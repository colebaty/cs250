# Assignment 7 Notes

## ADTs

### Customer

- First Name
- Last Name
- isPreffered
- car
- balance

### Staff

- First name
- last name
- car
- salary

## Synopsis

Process `txt` files and print information to console screen.

Ensure member variables are private; use getter, setter functions to manipulate data.

## Approach

Implement a `Person` base class, from which `Customer` and `Staff` classes can be derived.

### `Person` Class

- string firstname
- string lastname
- string car

## Requirements

- [ ] Compilation
- [ ] "correct" number of `.h`, `.cpp`, `.txt` files
- [ ] use getter, setter functions
- [ ] private member variables
- [ ] standard style stuff

## Algorithm

```
//print rental records for ODU rentals
    //open, read input files
        //read staff.txt
            // read first line for number of staff
            //create dynamic array of staff with number read from first line
            // read each remaining line; populate array
        //read customers.txt
            // read first line for number of staff
            //create dynamic array of customers with number read from first line
            // read each remaining line; populate array
    //close input files
    //print data
        //print program header
        //print staff header
            //print staff data
        //print customer header
            //print customer data
```