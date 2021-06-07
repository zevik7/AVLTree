#include "UI.h"

UI::UI()
{
    //Load font
    fontLoad();
    //Tao text box
    rectmaking();
    //Tao nut
    buttonLoad();
}

void UI::fontLoad()
{
    if (!font.loadFromFile("Assets/Quicksand-VariableFont_wght.ttf"))
    {
        cout << "UI font not load";
    }
}

void UI::buttonLoad()
{
    for (int i = 0; i < 3; i++)
    {
        static float k = 110.f;
        button[i].setFillColor(sf::Color(176, 227, 255, 255));
        button[i].setOutlineColor(sf::Color::Black);
        button[i].setOutlineThickness(2);
        button[i].setSize(sf::Vector2f(140.f, 51.f));
        button[i].setPosition(sf::Vector2f(850.f, k));
        k += 80.f;

        string string2[3] = { "Thêm", "Xóa" , "Tìm kiem" };
        buttontext[i].setCharacterSize(21);
        buttontext[i].setPosition(sf::Vector2f(button[i].getPosition().x + 24, button[i].getPosition().y + 15));
        buttontext[i].setString(string2[i]);
        buttontext[i].setFillColor(sf::Color::Black);
        buttontext[i].setFont(font);
    }

}

//text box !
void UI::rectmaking()
{
    rectangle.setFillColor(sf::Color::White);
    rectangle.setSize(sf::Vector2f(140.f, 55.f));
    rectangle.setPosition(sf::Vector2f(850.00f, 41.f));

    //Noi dung text box
    text.setCharacterSize(24);
    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setPosition(sf::Vector2f(rectangle.getPosition().x + 4, rectangle.getPosition().y + 10));
    
    //Label text box
    mesg.setCharacterSize(22);
    mesg.setFont(font);
    mesg.setString("Nhap gia tri: ");
    mesg.setFillColor(sf::Color::White);
    mesg.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y - 30));
}

void UI::settitle(sf::RenderWindow& window)
{
    titleText.setCharacterSize(50);
    titleText.setOutlineColor(sf::Color::White);
    titleText.setOutlineThickness(2);
    titleText.setPosition(sf::Vector2f(window.getSize().x * 3 / 9, window.getSize().y * 1 / 29));
    titleText.setFont(font);
    titleText.setString("Cay AVL");
    titleText.setFillColor(sf::Color::Blue);
}
void UI::UIdraw(sf::RenderWindow& window)
{
    for (int i = 0; i < 3; i++)
    {
        window.draw(button[i]);
        window.draw(buttontext[i]);
    }

    window.draw(mesg);
    window.draw(rectangle);
    window.draw(titleText);
    window.draw(text);

}