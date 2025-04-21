#include <iostream>
#include "httplib.h" // Include a lightweight HTTP library

int main() {
    httplib::Server svr;

    // HTML for the dark mode palette
    std::string html = R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Fancade Dark Mode Palette</title>
        <style>
            body {
                background-color: #121212;
                color: #ffffff;
                font-family: Arial, sans-serif;
                margin: 0;
                padding: 0;
                display: flex;
                justify-content: center;
                align-items: center;
                height: 100vh;
            }
            .palette {
                display: flex;
                gap: 10px;
            }
            .color-box {
                width: 50px;
                height: 50px;
                border-radius: 5px;
                border: 1px solid #ffffff;
            }
            .color1 { background-color: #1f1f1f; }
            .color2 { background-color: #292929; }
            .color3 { background-color: #333333; }
            .color4 { background-color: #3d3d3d; }
            .color5 { background-color: #474747; }
        </style>
    </head>
    <body>
        <div class="palette">
            <div class="color-box color1"></div>
            <div class="color-box color2"></div>
            <div class="color-box color3"></div>
            <div class="color-box color4"></div>
            <div class="color-box color5"></div>
        </div>
    </body>
    </html>
    )";

    // Serve the HTML content on the root URL
    svr.Get("/", [&](const httplib::Request &, httplib::Response &res) {
        res.set_content(html, "text/html");
    });

    std::cout << "Server is running on http://localhost:8080" << std::endl;
    svr.listen("localhost", 8080);

    return 0;
}
