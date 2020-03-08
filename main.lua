-- main.lua
--
-- Twilight in Oregon: A Christine Sorney Mystery
--
-- Run: love .
--
-- Made by cnsorensen
--

-- Called only once. When game started, it loads resources, initializes variable,
--  and set specific settings. Can be done anywhere but doing it here saves
--  systems resources.
function love.load()
  printx = 400
  printy = 300

  printx2 = 300
  printy2 = 200

  -- This line has no effect because it's not in love.draw()
  --love.graphics.setColor(0, 0, 0)
end

-- Where arll the draing happens. If you call any of the love.graphics.draw outside of
--  this function then it's not going to have any effect. This function is also called
--  continuously so keep in mind that if you change the font/color/model/etc at the
--  end of the function then it will have an effect on things at the beginning of the
--  function
function love.draw()
  love.graphics.print("Hello world", printx, printy)
  love.graphics.print("Yep", printx2, printx2)
end

-- number x, y = coordinates of mouse position
-- number button = button that was pressed.
--        1 - primary (left), 2 - secondary, 3 - middle
-- bool istouch = true if mouse button press originated from a touchscreen touch-press (??)
-- number presses = number of presses in a short time frame and small area (double click etc)
function love.mousepressed(x, y, button, istouch, presses)
  if button == 1 and presses == 2 then
    printx = x
    printy = y
  end
end

-- Mouse released. params same as mouse pressed.
-- Website gives an example of a slingshot for this
-- Coordinates are kind of off. Need to look into if I'm using this
function love.mousereleased(x, y, button, istouch)
  if button == 2 then
    printx2 = x
    printy2 = y
  end
end

-- KeyConstant key = char pressed,
-- Scancode scancode = scancode representing the pressed key (??)
-- bool isrepeat = whether this keypress even is a repeat
function love.keypressed(key)
  -- Exit game
  if key == 'q' or key == 'escape' then
    love.event.quit()
  end
end

-- Same as keypressed minus isrepeat
function love.keyreleased(key)
end

-- Called whenever user clicks off and on the LOVE window.
-- Example, user is playing in a windowed fame and the user clicks on internet browser
--  the game can be notified and auto pause the game
function love.focus(f)
end

-- Called when user clicks window's close button (x).
-- For example, it can save state before it closes
function love.quit()
end

