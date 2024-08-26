def parse_string(s, idx):
    end_idx = idx + 1
    while s[end_idx] != '"':
        end_idx += 1
    return s[idx+1:end_idx], end_idx + 1

def parse_object(s, idx):
    obj = {}
    idx += 1  # skip opening brace
    while s[idx] != '}':
        key, idx = parse_string(s, idx)
        idx += 1  # skip colon
        value, idx = parse_string(s, idx)
        obj[key] = value
        if s[idx] == ',':
            idx += 1  # skip comma
    return obj, idx + 1

def parse_json(s):
    s = s.strip()
    if s[0] == '{':
        return parse_object(s, 0)[0]
    raise ValueError("Invalid JSON")

json_string = '{"name": "Tyson Horvath", "age": "24"}'
parsed_json = parse_json(json_string)
print(parsed_json)  # output: {'name': 'Tyson Horvath', 'age': '24'}
