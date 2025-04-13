local player = game:GetService("Players").LocalPlayer
local TweenService = game:GetService("TweenService")


local container = player.PlayerGui:FindFirstChild("NotificationContainer")
if not container then
    container = Instance.new("Frame")
    container.Name = "NotificationContainer"
    container.Parent = player.PlayerGui
    container.Size = UDim2.new(1, 0, 1, 0)
    container.BackgroundTransparency = 1
    container.Position = UDim2.new(0, 0, 0, 0)
end
task.wait(0.05)
local function Checkframes()
	local count = 0
	for _, gui in ipairs(container:GetChildren()) do
		if gui:IsA("ScreenGui") and gui:GetAttribute("Active") then
			count += 1
		end
	end
	return count
end
local existing = Checkframes()

local gui = Instance.new("ScreenGui")
gui.Name = "SimpleNotify"
gui.ResetOnSpawn = false
gui.Parent = container
gui:SetAttribute("Active", true) 

local mainFrame = Instance.new("Frame")
mainFrame.Name = "MainFrame"
mainFrame.Parent = gui
mainFrame.BackgroundColor3 = Color3.new(0, 0, 0)
mainFrame.BackgroundTransparency = 0.15
local offset = -80 - ((existing - 1) * 70) 
mainFrame.Position = UDim2.new(1, 0, 1, offset)
mainFrame.Size = UDim2.new(0, 260, 0, 60) 
mainFrame.AnchorPoint = Vector2.new(1, 1) 

local title = Instance.new("TextLabel")
title.Name = "Title"
title.Parent = mainFrame
title.BackgroundTransparency = 1
title.Position = UDim2.new(0, 12, 0, 8)
title.Size = UDim2.new(1, -24, 0, 24)
title.Font = Enum.Font.GothamBold
title.Text = "INJECTED"
title.TextColor3 = Color3.new(1, 1, 1)
title.TextSize = 16
title.TextXAlignment = Enum.TextXAlignment.Left

local message = Instance.new("TextLabel")
message.Name = "Message"
message.Parent = mainFrame
message.BackgroundTransparency = 1
message.Position = UDim2.new(0, 12, 0, 32)
message.Size = UDim2.new(1, -24, 0, 20)
message.Font = Enum.Font.Gotham
message.Text = "Injection Succeded."
message.TextColor3 = Color3.new(0.8, 0.8, 0.8)
message.TextSize = 14
message.TextXAlignment = Enum.TextXAlignment.Left

local slideIn = TweenService:Create(
	mainFrame,
	TweenInfo.new(0.7, Enum.EasingStyle.Quad, Enum.EasingDirection.Out),
	{Position = UDim2.new(1, -20, 1, offset)}
)



slideIn:Play()

wait(2.5) 

local slideOut = TweenService:Create(
    mainFrame,
    TweenInfo.new(0.4, Enum.EasingStyle.Quad),
    {Position = UDim2.new(1, 300, 1, offset)}
)
slideOut:Play()

slideOut.Completed:Wait()
gui:SetAttribute("Active", false)
gui:Destroy()
