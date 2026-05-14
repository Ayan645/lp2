def chatbot(first_time=True):
    if first_time:
        print("Welcome to Customer Support Chatbot!")
        print("You can ask about products, prices, orders, delivery, returns, and payment methods.")
        print("Type bye to exit.\n")

    user = input("You: ").lower().strip()

    if user == "bye":
        print("Bot: Thank you for visiting. Have a great day!")

    elif user == "hi" or user == "hello" or user == "hey":
        print("Bot: Hello! How can I help you today?\n")
        chatbot(False)

    elif "product" in user:
        print("Bot: We have mobiles, laptops, and headphones available.\n")
        chatbot(False)

    elif "price" in user:
        print("Bot: Prices in INR - mobiles from Rs. 10,000, laptops from Rs. 35,000, and headphones from Rs. 1,500.\n")
        chatbot(False)

    elif "order" in user:
        print("Bot: Please provide your order ID to check status.\n")
        chatbot(False)

    elif "delivery" in user:
        print("Bot: Delivery usually takes 3 to 5 business days.\n")
        chatbot(False)

    elif "return" in user:
        print("Bot: Products can be returned within 7 days of delivery.\n")
        chatbot(False)

    elif "payment" in user:
        print("Bot: We support UPI, Debit Card, Credit Card, and Net Banking.\n")
        chatbot(False)

    else:
        print("Bot: Sorry, I didn't understand.\n")
        chatbot(False)


if __name__ == "__main__":
    chatbot()

"""
============================================================================
                                THEORY
============================================================================

AIM:
To implement a simple rule-based chatbot using Python.

----------------------------------------------------------------------------

WHAT IS A CHATBOT?

A chatbot is a software program that:
- interacts with users
- answers queries automatically
- simulates human conversation

----------------------------------------------------------------------------

WHAT IS RULE-BASED CHATBOT?

A rule-based chatbot works using:
- predefined rules
- if-else conditions
- keyword matching

Example:
If user types "price"
→ bot shows product prices

----------------------------------------------------------------------------

WORKING OF PROGRAM

1. User enters message
2. Message converted to lowercase
3. Program checks conditions
4. Matching response displayed
5. Chat continues recursively

----------------------------------------------------------------------------

KEY FUNCTIONS USED

.lower()
- converts text to lowercase

.strip()
- removes extra spaces

input()
- takes user input

print()
- displays chatbot response

----------------------------------------------------------------------------

WHAT IS NLP?

NLP = Natural Language Processing

It allows computers to:
- understand human language
- process text
- generate responses

This chatbot is a basic NLP example.

----------------------------------------------------------------------------

LIMITATIONS OF THIS CHATBOT

1. Cannot understand complex sentences
2. Cannot learn automatically
3. No machine learning used
4. Limited responses
5. Cannot handle spelling mistakes

----------------------------------------------------------------------------

HOW TO IMPROVE?

1. Use Machine Learning
2. Use NLTK or spaCy
3. Use AI models like GPT
4. Add database support
5. Add speech recognition

----------------------------------------------------------------------------

APPLICATIONS

1. Customer support
2. Banking systems
3. E-commerce websites
4. Hospital support systems
5. Virtual assistants

----------------------------------------------------------------------------

ADVANTAGES

1. Fast responses
2. Available 24/7
3. Reduces human work
4. Easy to develop

----------------------------------------------------------------------------

DISADVANTAGES

1. Limited intelligence
2. No emotions
3. Cannot understand context properly

----------------------------------------------------------------------------

OUTPUT EXAMPLE

Welcome to Customer Support Chatbot!

You: hi
Bot: Hello! How can I help you today?

You: price
Bot: Prices in INR - mobiles from Rs. 10,000...

You: bye
Bot: Thank you for visiting. Have a great day!

----------------------------------------------------------------------------

VIVA QUESTIONS

1. What is chatbot?
Software that interacts with users automatically.

2. What type of chatbot is this?
Rule-based chatbot.

3. What is NLP?
Natural Language Processing.

4. Difference between AI chatbot and rule-based chatbot?
AI chatbot learns automatically while rule-based uses fixed rules.

5. Which language is used?
Python.

============================================================================
"""