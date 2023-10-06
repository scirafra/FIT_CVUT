## Step 1: Clone the Repository

To download the project to your local machine, you need to clone the repository.

1. On the GitHub repository page, find the green "Code" button, and click it. It's located near the top-right corner of the page.

2. You'll see a URL for the repository. You can choose to use HTTPS or SSH for cloning. Click on the clipboard icon to copy the URL.

3. Open your terminal or command prompt on your local machine.

4. Navigate to the directory where you want to download the repository.

5. To clone the repository using HTTPS, run the following command:

   ```bash
   git clone https://github.com/scirafra/msd_interview_task.git

## Step 2: Build the Docker Image
Open your terminal, navigate to the directory containing your Dockerfile and application code, and build the Docker image using the following command:

`docker build -t my-app-image .`

Replace `my-app-image` with your desired image name.

## Step 3: Run a Docker Container

After building the Docker image, you can create and run a container from it with the following command:

`docker run -d --name my-app-container my-app-image`

- `-d`: Run the container in detached mode.
- `--name my-app-container`: Assign a name to your container (replace my-app-container with your desired name).
- `my-app-image`: The name of the Docker image you built.


## Step 4: Check Running Containers

To view the running containers, use the following command:



`docker ps`

You should see your container listed with its ID, name, and status.

## Step 5: Stop and Remove the Container

When you're finished with your container, you can stop and remove it with the following commands:

`docker stop my-app-container`
`docker rm my-app-container`

Replace my-app-container with the actual name of your container.
