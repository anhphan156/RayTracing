#include "Application.h"
#include "Layer.h"
#include "RayTracingSettings.h"

Application::Application()
{
	if (!glfwInit()) std::abort();
	const char* glsl_version = "#version 330";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	m_window = glfwCreateWindow(1280, 720, "Ray Tracing", NULL, NULL);
	if (!m_window) std::abort();
	glfwMakeContextCurrent(m_window);

	if(glewInit() != GLEW_OK) std::abort();
	glClearColor(.1f, .1f, .1f, 1.f);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.WantCaptureMouse = true;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(m_window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

Application::~Application()
{
}

void Application::Run()
{
	shared_ptr<Layer> settings = make_shared<RayTracingSettings>();
	m_layers.push_back(settings);
	while (glfwWindowShouldClose(m_window) == 0 && glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();
		for (auto& layer : m_layers) {
			layer->OnUIRender();
		}

		// Render
		int display_w, display_h;
		glfwGetFramebufferSize(m_window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(m_window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(m_window);
	glfwTerminate();
}
