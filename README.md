Sure! Here's the updated version of the `README.md` file in English, with flags for the languages used and improved layout:

```markdown
# Doodle Pro

**Doodle Pro** is a parallel processing application that simulates I/O tasks using multiple threads. The system manages different storage providers (AWS, Azure, Google Cloud, Local) and executes tasks simultaneously to optimize processing time. This project was developed to demonstrate the use of **threads** and **concurrency** in data processing within a simulated environment.

## Features

- Simulates processing tasks across multiple storage providers.
- Parallel task execution using **DispatchQueue** in Swift to manage multiple threads.
- Simulates I/O operations with a 2-second delay (representing processing time).

## Technologies Used

- **Swift 5** 🇺🇸: The primary language used for implementing the application.
- **DispatchQueue** 🇺🇸: For managing concurrency and asynchronously executing tasks.
- **RunLoop** 🇺🇸: To ensure the program continues running until asynchronous tasks are completed.

## Project Structure

- **ProcessingTask.swift**: Defines the structure that stores information about the processing task.
- **Main.swift**: Contains the main function that creates and manages tasks, as well as executes parallel processing.
- **README.md**: This explanatory document.

## How to Run

### Requirements

- Xcode installed (recommended for Swift development).
- Operating System: macOS or any system that supports Swift.

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/doodle-pro.git
   ```

2. Open the project in Xcode.

3. Build and run the project in Xcode.

4. The program will create 4 threads and simulate processing tasks from different storage providers. Output will be printed in the Xcode console.

## Example Output

```bash
Thread 0: Processing data in AWS at path s3://my-bucket/data
Thread 1: Processing data in Azure at path azure://my-container/data
Thread 2: Processing data in Google Cloud at path gcs://my-bucket/data
Thread 3: Processing data in Local at path /local/disk/path

Thread 0: Finished processing in AWS
Thread 1: Finished processing in Azure
Thread 2: Finished processing in Google Cloud
Thread 3: Finished processing in Local

Main: All threads finished.
```

## Comparative Graphs

Below are some charts comparing **Doodle Pro**'s performance with other engines:

### Execution Time by Storage Provider

The chart below compares the execution time for simulated tasks across different storage providers using **Doodle Pro** and other engines like **AWS Lambda**, **Google Cloud Functions**, and **Azure Functions**.

![Execution Time Comparison](images/execution_time_comparison.png)

### Parallel Processing Performance

This chart compares **Doodle Pro** with other parallel processing engines based on the number of tasks processed per second.

![Parallel Processing Performance](images/parallel_processing_performance.png)

### Memory Usage Analysis

This chart compares memory usage between **Doodle Pro** and other engines when processing multiple tasks simultaneously.

![Memory Comparison](images/memory_comparison.png)

## Contribution

Contributions are welcome! If you have suggestions, improvements, or fixes, feel free to open a **pull request**.

### Steps to contribute

1. Fork the repository.
2. Create a new **branch** for your changes.
3. Make the necessary changes and submit a **pull request**.

## License

This project is licensed under the [MIT License](LICENSE).
```

### Adding Flags for Languages

In this updated version, I’ve added 🇺🇸 (USA flag) next to the technologies used (Swift and DispatchQueue) to indicate the programming languages. You can easily add other flags depending on the programming languages you use, for example:

- 🇺🇸 for English-based languages (like Swift, Python, JavaScript, etc.).
- 🇧🇷 for Portuguese, 🇪🇸 for Spanish, and so on, depending on the content.

### How to Add Images:

1. **Add images to the repository**: Create a folder called `images` or any other desired name to store the images in your repository. Place the images you want to compare, such as graphs and screenshots, in this folder.
   
2. **Link the images in `README.md`**: Use the markdown syntax `![alt text](path_to_image)` to add images to your `README.md`. For example:

   ```markdown
   ![Execution Time Comparison](images/execution_time_comparison.png)
   ```

3. **Ensure images are optimized**: To avoid making the repository too large, compress the images (e.g., PNG or JPEG with good quality) before uploading.

### Creating Comparative Graphs

For the comparative graphs, you can use tools such as **Matplotlib** (Python), **Excel**, or **Google Sheets**, and then export the results as images to include them in your `README.md`.

Here are some graph types you could use:

- **Bar Chart**: For showing execution time across different storage providers.
- **Line Chart**: For comparing parallel processing performance in different engines.
- **Pie Chart or Stacked Bar Chart**: For visualizing memory usage across engines.

Once you generate these graphs, save them as images and upload them to your repository under the `images` folder.

### Conclusion

This README provides a comprehensive overview of your project in English, with added visualizations to compare performance with other engines. You can further customize it based on additional features or improvements you make to the project. Let me know if you need further adjustments!