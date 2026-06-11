local key = KEYS[1]
local capacity = tonumber(ARGV[1])
local refill_rate = tonumber(ARGV[2])
local now = tonumber(ARGV[3])
local requested = tonumber(ARGV[4])

-- Fetch current bucket state
local data = redis.call('HMGET', key, 'tokens', 'last_updated')
local tokens = tonumber(data[1])
local last_updated = tonumber(data[2])

-- Initialize bucket if user dne
if not tokens then
    tokens = capacity
    last_updated = now
else 
    local elapsed = now - last_updated
    if elapsed > 0 then 
        tokens = math.min(capacity, tokens + (elapsed * refill_rate))
        last_updated = now
    end 
end 

-- Rate Limiter Logic
if tokens >= requested then
    tokens = tokens - requested 
    redis.call('HMSET', key, 'tokens', tokens, 'last_updated', last_updated)
    return 1    -- Allowed
else 
    redis.call('HMSET', key, 'tokens', tokens, 'last_updated', last_updated)
    return 0    -- Throtted (HTTP 429)
end