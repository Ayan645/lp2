# in exam you can change the topic of expert system
# example:
# hospital system
# travel guide
# restaurant recommendation
# career guidance
# education system etc.

def hospital_expert_system():

    print("Welcome to Hospital Expert System")
    print("Answer the following questions.")
    print("Type yes or no\n")

    fever = input("Do you have fever? ").lower()

    cough = input("Do you have cough? ").lower()

    chest_pain = input("Do you have chest pain? ").lower()

    injury = input("Do you have any injury or fracture? ").lower()

    stomach_pain = input("Do you have stomach pain? ").lower()

    print("\n--- Diagnosis Suggestion ---")

    if fever == "yes" and cough == "yes":

        print("You may have a viral infection or flu.")
        print("Suggested Department: General Medicine")

    elif chest_pain == "yes":

        print("You may need a heart check-up.")
        print("Suggested Department: Cardiology")

    elif injury == "yes":

        print("You may require bone or injury treatment.")
        print("Suggested Department: Orthopedics")

    elif stomach_pain == "yes":

        print("You may have digestive issues.")
        print("Suggested Department: Gastroenterology")

    else:

        print("Please consult a General Physician for further diagnosis.")

    print("\nThank you for using Hospital Expert System.")


hospital_expert_system()

"""
============================================================================
                                THEORY
============================================================================

AIM:
To implement an Expert System using Python.

----------------------------------------------------------------------------

WHAT IS AN EXPERT SYSTEM?

An Expert System is an AI-based program that:
- mimics decision making of human experts
- provides suggestions or diagnosis
- uses rules and knowledge base

Example:
Hospital diagnosis system
Banking support system
Travel recommendation system

----------------------------------------------------------------------------

COMPONENTS OF EXPERT SYSTEM

1. Knowledge Base
   - Stores facts and rules

2. Inference Engine
   - Applies rules and makes decisions

3. User Interface
   - Interaction between user and system

4. Explanation Facility
   - Explains the decision

----------------------------------------------------------------------------

WORKING OF THIS PROGRAM

1. User answers questions
2. System checks conditions
3. Matching rule executes
4. Suggestion displayed

Example:
If fever = yes
AND cough = yes
→ Viral infection

----------------------------------------------------------------------------

WHAT ARE IF-ELSE RULES?

Rules used for decision making.

Example:

IF fever == yes
AND cough == yes
THEN flu

----------------------------------------------------------------------------

FORWARD CHAINING

Data-driven approach.

Starts with:
FACTS

Then applies:
RULES

Finally gives:
CONCLUSION

This program uses Forward Chaining.

----------------------------------------------------------------------------

BACKWARD CHAINING

Goal-driven approach.

Starts from:
GOAL

Then checks supporting facts.

----------------------------------------------------------------------------

ADVANTAGES

1. Fast decision making
2. Reduces human effort
3. Available anytime
4. Consistent output

----------------------------------------------------------------------------

DISADVANTAGES

1. Limited knowledge
2. Cannot learn automatically
3. Difficult to maintain large rule sets

----------------------------------------------------------------------------

APPLICATIONS

1. Medical diagnosis
2. Banking systems
3. Education systems
4. Agriculture systems
5. Technical support

----------------------------------------------------------------------------

TIME COMPLEXITY
Depends on number of rules checked.

For this program:
:contentReference[oaicite:0]{index=0}

Where:
n = number of rules

----------------------------------------------------------------------------

OUTPUT EXAMPLE

Welcome to Hospital Expert System

Do you have fever? yes
Do you have cough? yes

You may have a viral infection or flu.
Suggested Department: General Medicine

----------------------------------------------------------------------------

VIVA QUESTIONS

1. What is Expert System?
AI system that mimics human expert decisions.

2. What is Knowledge Base?
Collection of rules and facts.

3. What is Inference Engine?
Applies rules to make decisions.

4. What is Forward Chaining?
Starts from facts and reaches conclusion.

5. Difference between chatbot and expert system?
Chatbot handles conversation while expert system gives decisions.

============================================================================
"""