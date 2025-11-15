#include "Nova.h"
#include "Core/KeyCodes.h"

class MyApp : public Nova::Application {
public:
    void Setup() override { // Run once on startup
        window->SetTitle("My Application Title"); // Change Window Title
        window->SetSize(800, 600); // Resize Window
    }

    void Update() override { // Run once per frame
        //renderer->background(0);
        Nova::Color::RGBA me = Nova::Color::White;
        //renderer->fill(me);
        //renderer->noStroke();
        int al = 50;
        //renderer->rect(al, 0, window->GetWidth()/3, window->GetHeight(), Nova::Color::RGBA(255, 64, 0, 128));
        //renderer->stroke(me);
        //renderer->noFill();
        //renderer->ellipse(10, 10, 3, 5);
    }

    void KeyPressed() override { // Run when a key is pressed (Only for inital press, key repeats are ignored)

    }

    void KeyReleased() override { // Run when a key is released

    }

    void KeyRepeat() override { // Run when a key is repeated

    }

    void MousePressed() override { // Run when a mouse button is pressed (left, middle, or right)

    }

    void MouseReleased() override { // Run when a mouse button is released (left, middle, or right)

    }

    void MouseDragged() override { // Run when the mouse is moved while a button is held

    }

    void MouseMoved() override { // Run when the mouse is moved while a button is not held

    }

    void MouseScrolled() override { // Run when the mouse wheel is scrolled

    }

    void WindowResized() override { // Run when the window is resized

    }

    void WindowCloseAttempt() override { // Run when the user clicks the close button (Useful for saving work before shutdown)
        // Use `running = true;` to cancel window close
    }
};

Nova::Application* CreateApplication() {
    return new MyApp();
}