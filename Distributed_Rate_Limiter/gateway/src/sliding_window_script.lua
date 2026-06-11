local key = KEYS[1]
local limit = tonumber(ARGV[1])
local window = tonumber(ARGV[2])
local now = tonumber(ARGV[3])
local unique_id = ARGV[4]
local window_start = now - window
redis.call('ZREMRANGEBYSCORE', key, '-inf', window_start)
local current_requests = redis.call('ZCARD', key)
if current_requests >= limit then
    return 0
end
redis.call('ZADD', key, now, now .. '-' .. unique_id)
redis.call('EXPIRE', key, window)
return 1