# SRS Development Approach
This document provides guidance on how to write an Software Requirements Specification (SRS) from scratch.

## SRS Structure
Start by creating a document who's structure aligns with the guidance provided by [SRS Structure](1_srsStructure.md#srs-structure).

## Generating SRS Content
Generally it is not feasible to just sit down and write an SRS with well-defined, testable requirements from start to finish. In practice, it is best to start with a concept for the library or application that is being developed. Determine the high-level goal or purpose of the software being developed and start developing the document using an iterative approach where each iteration provides lower-level details that are closer to the desired functionality. This iterative approach is known as "deriving requirements".

### Requirements Generation Process
The following process provides guidance on how to generate requirements for a software application. The process assumes that you are starting with just an idea, so no tools, preparation or prior material are required to execute this process.

1) Define the application's purpose
2) Define the application boundaries
3) 

#### Define the application's purpose
This is the ideas phase of the software development process. At this point, you should be focusing on what the problem that you are trying to solve is. By creating a clear and concise defintion of the problem, you are inadvertently defining the core scope of your software application. In addition to identifying the problem, you should also define what the return on investment will be for creating the applicaiton.

By defining the application's scope and identifying the benifits of using the application, you are providing the foundation for the technical decisions that you will have to make during the development of the application. For example, if you are creating a new tool to identify and extract software metrics to save time manually combing through the data and allowing you to identify second-level patterns in the development process. If you the result of developing this tool is a one time saving of a couple of days work reading the data then it may not be worth it to create an extensive pattern recognizition tool in C++ due to the heavy cost associated with designing, developing and testing that application. For that particular benifit, it may only be worth it to create a quick and dirty python script that after the time spent developing has allowed you to save half of the overall time. However, if instead you are working for a corporation with thousands of engineers parsing terrabytes of data over the course of several years, then creating a more robust tool in C++ makes sense due to the need for a more efficient tool where memory management is essential to the accomplishment of the task.

#### Define the application boundaries
Now that the task is well defined, the inputs and outputs to the application can be defined. Continuing along the same thread of the examples in the previous section, the external interfaces to the application can drastically change the approach taken when designing and implementing the application. When defining the boundaries, the following things should be documented:

-How is the application started?
-What other applications or systems will be interacting with the application being created?
-What data is fed in to the system to be processed?
-What are the outputs of the application?

#### 
