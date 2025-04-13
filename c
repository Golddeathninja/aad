local player = game:GetService("Players").LocalPlayer
local TweenService = game:GetService("TweenService")
if player:FindFirstChild("PlayerGui") and player.PlayerGui:FindFirstChild("ExecutionNotification") then
    player.PlayerGui.ExecutionNotification:Destroy()
end
local gui = Instance.new("ScreenGui")
gui.Name = "ExecutionNotification"
gui.ResetOnSpawn = false
gui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
gui.Parent = player:WaitForChild("PlayerGui")
local mainFrame = Instance.new("Frame")
mainFrame.Name = "MainFrame"
mainFrame.Parent = gui
mainFrame.BackgroundColor3 = Color3.fromRGB(25, 25, 25)
mainFrame.BackgroundTransparency = 0.15
mainFrame.Position = UDim2.new(1, 310, 1, -110) 
mainFrame.Size = UDim2.new(0, 300, 0, 100)
mainFrame.AnchorPoint = Vector2.new(0, 0)
mainFrame.Active = true
mainFrame.Draggable = false
local corner = Instance.new("UICorner")
corner.CornerRadius = UDim.new(0, 8)
corner.Parent = mainFrame
local stroke = Instance.new("UIStroke")
stroke.Thickness = 1.5
stroke.Color = Color3.fromRGB(0, 255, 100)
stroke.Transparency = 0.7
stroke.Parent = mainFrame
local topBar = Instance.new("Frame")
topBar.Name = "TopBar"
topBar.Parent = mainFrame
topBar.BackgroundColor3 = Color3.fromRGB(20, 20, 20)
topBar.Size = UDim2.new(1, 0, 0, 25)
topBar.BorderSizePixel = 0
local topBarCorner = Instance.new("UICorner")
topBarCorner.CornerRadius = UDim.new(0, 6)
topBarCorner.Parent = topBar
local title = Instance.new("TextLabel")
title.Name = "Title"
title.Parent = topBar
title.BackgroundTransparency = 1
title.Position = UDim2.new(0, 10, 0, 0)
title.Size = UDim2.new(0, 200, 1, 0)
title.Font = Enum.Font.GothamBold
title.Text = "EXECUTION SUCCEDED"
title.TextColor3 = Color3.fromRGB(0, 255, 100)
title.TextSize = 14
title.TextXAlignment = Enum.TextXAlignment.Left
local contentFrame = Instance.new("Frame")
contentFrame.Name = "ContentFrame"
contentFrame.Parent = mainFrame
contentFrame.BackgroundTransparency = 1
contentFrame.Position = UDim2.new(0, 0, 0, 25)
contentFrame.Size = UDim2.new(1, 0, 1, -45) 
local icon = Instance.new("ImageLabel")
icon.Name = "Icon"
icon.Size = UDim2.new(0, 36, 0, 36)
icon.Position = UDim2.new(0.05, 0, 0.62, -18)
icon.Image = "rbxassetid://137218943079626" 
icon.BackgroundTransparency = 1
icon.Parent = contentFrame
local text = Instance.new("TextLabel")
text.Name = "Notify"
text.Size = UDim2.new(0.75, 0, 0.5, 0)
text.Position = UDim2.new(0.2, 0, 0.25, 0)
text.BackgroundTransparency = 1
text.Text = "SCRIPT EXECUTED"
text.TextColor3 = Color3.fromRGB(0, 255, 100)
text.TextSize = 18
text.Font = Enum.Font.GothamBold
text.TextXAlignment = Enum.TextXAlignment.Left
text.Parent = contentFrame
local subtext = Instance.new("TextLabel")
subtext.Name = "SubText"
subtext.Size = UDim2.new(0.75, 0, 0.3, 0)
subtext.Position = UDim2.new(0.2, 0, 0.6, 0)
subtext.BackgroundTransparency = 1
subtext.Text = "Didn't Work? Try a different Script"
subtext.TextColor3 = Color3.fromRGB(200, 200, 200)
subtext.TextSize = 14
subtext.Font = Enum.Font.Gotham
subtext.TextXAlignment = Enum.TextXAlignment.Left
subtext.Parent = contentFrame
local function animate()
    
    local slideIn = TweenService:Create(
        mainFrame,
        TweenInfo.new(0.5, Enum.EasingStyle.Quad),
        {Position = UDim2.new(1, -310, 1, -110)}
    )
    slideIn:Play()
    
    
    wait(3)
    
    
    local uneedtLeave = TweenService:Create(
        mainFrame,
        TweenInfo.new(0.8, Enum.EasingStyle.Quad),
        {Position = UDim2.new(1, 310, 1, -110)}
    )
    uneedtLeave:Play()
    
    
    uneedtLeave.Completed:Wait()
    gui:Destroy()
end

animate()
