class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exclusive_times(n, 0);
        stack<int> func_stack;
        int prev_time = 0;

        for (const string& log : logs) {
            // Parse the log string: "id:status:timestamp"
            stringstream ss(log);
            string id_str, status, time_str;
            
            getline(ss, id_str, ':');
            getline(ss, status, ':');
            getline(ss, time_str, ':');
            
            int func_id = stoi(id_str);
            int timestamp = stoi(time_str);

            if (status == "start") {
                // If a function was already running, accumulate its time up to this point
                if (!func_stack.empty()) {
                    exclusive_times[func_stack.top()] += timestamp - prev_time;
                }
                // Push the new function onto the stack and update the time marker
                func_stack.push(func_id);
                prev_time = timestamp;
            } else { // status == "end"
                // The current function ends, so it runs through the end of this timestamp
                exclusive_times[func_stack.top()] += timestamp - prev_time + 1;
                func_stack.pop();
                // The next function (if any) resumes at the next timestamp unit
                prev_time = timestamp + 1;
            }
        }

        return exclusive_times;

    }
};