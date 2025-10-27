# Final Project: Building a Web Application with Zig

## Overview
In this project, students will apply what they have learned about Zig to develop a fully functional web application. This project will allow students to demonstrate their understanding of Zig programming concepts, best practices for structuring Zig projects, and the use of external libraries.

## Objectives
- To create a web application using the Zig programming language.
- To understand project structure and manage dependencies using Zig's package manager.
- To implement server-side logic using Zig and handle HTTP requests and responses.
- To utilize external libraries effectively in a Zig project.
- To learn about routing, templates, and session management in web applications.

## Requirements
1. **Project Structure**: Create a directory for the web application with the following structure:
    ```
    mywebapp/
    ├── zig.mod
    ├── src/
    │   ├── main.zig
    │   └── routes.zig
    ├── templates/
    │   └── index.zig
    └── static/
    ```

2. **zig.mod File**: This file should contain information about the project and its dependencies. Here is a simple example:
    ```zig
    module mywebapp;

    dep "zig-http"; // Include the zig-http library for HTTP handling
    dep "zig-template"; // Include a template library if needed
    ```

3. **Main Application File (main.zig)**: The main entry point of the application.
    ```zig
    const std = @import("std");
    const http = @import("zig-http");
    const routes = @import("routes");

    pub fn main() void {
        var server = http.Server.listen("127.0.0.1:8080") catch unreachable;
        defer server.close();

        while (true) {
            var client = server.accept();
            defer client.close();
            routes.handleRequest(client); // Handle requests using custom routing
        }
    }
    ```

4. **Routing Logic (routes.zig)**: Implement a simple routing mechanism that responds to different endpoints.
    ```zig
    const std = @import("std");

    pub fn handleRequest(client: *http.Client) void {
        // Basic routing logic
        const path = client.request.path;
        if (path == "/") {
            client.write("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello, World!\n");
        } else {
            client.write("HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n404 Not Found\n");
        }
    }
    ```

5. **Templates**: Students can implement a simple HTML template engine that can render HTML pages. Create an example template in `templates/index.zig`.

6. **Static Files**: Allow the serving of static files (e.g., CSS, JavaScript) from the `static` directory. Implement logic in `routes.zig` to serve these files.

## Guidelines
- **Documentation**: Students must document their code clearly, explaining the purpose of modules, functions, and any complex logic implemented.
- **Testing**: Implement basic unit tests to verify the functionality of the application, especially the routing logic.
- **Version Control**: Use Git for version control, ensuring commits are made for each significant change with meaningful messages.

## Delivery
Submit the project by organizing all files in a zip folder and provide a short README.md file that explains how to set up and run the web application. Include any external libraries used and their installation steps.

## Evaluation Criteria
- **Functionality**: The application meets the requirements set forth.
- **Code Quality**: Code is clean, well-organized, and follows Zig best practices.
- **Documentation**: Use of comments and a README file explaining the setup and functionality.
- **Testing**: Adequate testing is implemented to verify functionality.